from binary_to_decim_straight import int_bin_to_dec_str


def sum(first_num: str, second_num:str):
    summary = ''
    carry = 0
    for first_bit, second_bit in zip(first_num[::-1], second_num[::-1]):
        result = int(first_bit) + int(second_bit) + carry
        if result == 2:
            summary = '0' + summary
            carry = 1
        elif result == 3:
            summary = '1' + summary
            carry = 1  
        else: 
            summary = str(result) + summary
            carry = 0
    if first_num[0] == '1':
        summary = '1' + summary[1:]
    return summary

def dif(first_num: str, second_num: str):
    result = ''
    borrow = 0
    for i in range(len(first_num)-1, -1, -1):
        diff = int(first_num[i]) - int(second_num[i]) - borrow
        if diff < 0:
            diff += 2
            borrow = 1
        else:
            borrow = 0
        result = str(diff) + result

    return result

def straight_code_sum(first_num: str, second_num:str):
    summary = ''

    if first_num[0] == second_num[0]:
        summary = sum(first_num, second_num)
    else:
        if abs(int_bin_to_dec_str(first_num)) >= abs(int_bin_to_dec_str(second_num)):
            summary = dif(first_num, second_num)
            if first_num[0] == '0':
                summary = '0' + summary[1:]
        else:
            summary = dif(second_num, first_num)
            if second_num[0] == '0':
                summary = '0' + summary[1:]

    if len(summary) > 32:
        summary = summary[-32:]
    return summary


