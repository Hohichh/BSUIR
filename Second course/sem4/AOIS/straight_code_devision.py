from binary_to_decim_straight import int_bin_to_dec_str

def dif(first_num: str, second_num: str):
    result = ''
    borrow = 0
    if len(second_num) < len(first_num):
        second_num = second_num.zfill(len(first_num))

    for i in range(len(first_num)-1, -1, -1):
        diff = int(first_num[i]) - int(second_num[i]) - borrow
        if diff < 0:
            diff += 2
            borrow = 1
        else:
            borrow = 0
        result = str(diff) + result

    return result

def greater(first_num: str, second_num: str) -> bool:
    first_num = first_num.zfill(32)
    second_num = second_num.zfill(32)
    return first_num >= second_num

def straight_code_devision(first_num: str, second_num: str):
    result = ''
    if int_bin_to_dec_str(second_num) == 0:
        raise ZeroDivisionError("Devider equals zero!")
    if int_bin_to_dec_str(first_num) == 0:
        return first_num
    
    first_sign = first_num[0]
    second_sign = second_num[0]

    first_num = first_num[1:]
    second_num = second_num[1:]

    first_num = first_num.lstrip('0')
    second_num = second_num.lstrip('0')

    substr = ''
    remainder = ''
    i = 0
    #типа делим в столбик
    while i <= len(first_num):
        if i == 0:
            substr = first_num[:len(second_num)]
            i = len(second_num)

        if greater(substr, second_num) == True:
            result = result + '1'
            remainder = dif(substr, second_num)
            if i < len(first_num):
                remainder = remainder + first_num[i]
        else:
            result = result + '0'
            if i < len(first_num):
                remainder = substr + first_num[i]
        
        remainder = remainder.lstrip('0')
        if remainder == '':
            remainder = '0'
        substr = remainder
        i += 1

    result = result.zfill(32)

    if first_sign != second_sign:
        return '1' + result[1:]  
    else:
        return '0' + result[1:] 
    

