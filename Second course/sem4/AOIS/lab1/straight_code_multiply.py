from two_complement_sum import two_complement_sum
from straight_code_sum import straight_code_sum
from binary_to_decim_straight import int_bin_to_dec_str

#умножение чисел в прямом коде
def straight_multiply(first_num: str, second_num: str):

    if first_num == '0'*32 or second_num == '0'*32:
        return '0' * second_num
    
    first_sign = first_num[0]
    second_sign = second_num[0]

    result = '0' * 32
    #убираем знаковые биты
    first_num = first_num[1:]
    second_num = second_num[1:]
    #умножаем в столбик на каждый бит второго числа первое число и складываем получаенные результаты
    for i in range(len(second_num) - 1, -1, -1):
        if second_num[i] == '1':
            term = first_num + '0' * (len(second_num) - i - 1)  
            result = straight_code_sum(result, term)
   
    #обработка знака
    if first_sign != second_sign:
        return '1' + result[1:]  
    else:
        return '0' + result[1:]  






