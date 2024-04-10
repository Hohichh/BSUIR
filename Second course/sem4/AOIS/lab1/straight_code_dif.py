from straight_code_sum import straight_code_sum
from binary_to_decim_straight import int_bin_to_dec_str

#вычитание чисел в прямом коде
def straight_code_dif(first_num: str, second_num:str):
    difference = ''
    #обработка знака:
    #если второе число отрицательное:
    if second_num[0] == '1':
        second_num = '0' + second_num[1:]
        difference = straight_code_sum(first_num, second_num) # a - (-b) = a + b
    #если первое число отрицательное:
    elif first_num[0] == '1':
        second_num = '1' + second_num[1:]
        difference = straight_code_sum(first_num, second_num) # -a - b = -a + (-b) 
    else: #если оба числа положительные
        if abs(int_bin_to_dec_str(first_num)) >= abs(int_bin_to_dec_str(second_num)):
            difference = dif(first_num, second_num) #а > b => a - b = c
        else:
            difference = dif(second_num, first_num) #а < b => b - a = c
            difference = '1' + difference[1:] # -c
    
    return difference

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