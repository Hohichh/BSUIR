from binary_to_decim_straight import int_bin_to_dec_str

#сумма чисел в прямом коде
def straight_code_sum(first_num: str, second_num:str):
    summary = ''
    #если знаки чисел равны, то просто складываем 2 числа
    if first_num[0] == second_num[0]:
        summary = sum(first_num, second_num)
    else:
        #если знаки разные и первое по модулю больше либо равно второму
        if abs(int_bin_to_dec_str(first_num)) >= abs(int_bin_to_dec_str(second_num)):
            summary = dif(first_num, second_num) #вычитаем из первого второе
            if first_num[0] == '0': #обработка знака
                summary = '0' + summary[1:]
        else: #если знаки разные и первое по модулю меньше второго
            summary = dif(second_num, first_num) #вычитаем из второго первое
            if second_num[0] == '0': #обработка знака
                summary = '0' + summary[1:]
    #корректировка длины строки при переполнении
    if len(summary) > 32:
        summary = summary[-32:]
    return summary

#сумма чисел с одинаковыми знаками
def sum(first_num: str, second_num:str):
    summary = ''
    carry = 0
    #складываем в столбик каждый бит одного числа с другим
    for first_bit, second_bit in zip(first_num[::-1], second_num[::-1]):
        result = int(first_bit) + int(second_bit) + carry #результат сложения с переносом
        if result == 2:
            summary = '0' + summary
            carry = 1
        elif result == 3:
            summary = '1' + summary
            carry = 1  
        else: 
            summary = str(result) + summary
            carry = 0

    if first_num[0] == '1': #обработка знака
        summary = '1' + summary[1:]
    return summary

#разность чисел с одинаковыми знаками
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

