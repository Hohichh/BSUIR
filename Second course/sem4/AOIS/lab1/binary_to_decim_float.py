from binary_to_decim_straight import int_bin_to_dec_str
from decim_to_binary_float import decim_to_binary_float

def binary_to_decim_float(binary_number: str):
    if binary_number == '0'*32:
        return 0
    
    bin_sign, exponent_shift, mantissa = binary_number[0], binary_number[1:9], binary_number[9:]
    #определяем знак
    is_negative = False
    if bin_sign == '1':
        is_negative = True

    #переводим экспоненту в 10-й вид и получаем её степень
    exponent_shift = int_bin_to_dec_str(exponent_shift.zfill(32))
    exponent = exponent_shift - 127
    #если е >= 0, значит целая часть числа >= 1
    if exponent >= 0:
        integer_part_binary = '1' + mantissa[:exponent]
        fractional_part_binary = mantissa[exponent:]
        integer_part_decimal = int_bin_to_dec_str(integer_part_binary.zfill(32))
        fractional_part_decimal = dec_to_bin_fractional(fractional_part_binary)
        #ex:
        #в мантиссе записано 0001, добавляем ведущую 1, то есть норм. вид 1.0001
        #е = 2 > 0 => сдвиг был вправо на 2 => 100.01 - изначальное число 
    else:
        #если е < 0, то целая часть == 0
        fractional_part_binary = (-exponent-1) * '0' + '1' + mantissa
        fractional_part_decimal = dec_to_bin_fractional(fractional_part_binary)
        integer_part_decimal = 0
        #ex:
        #в мантиссе 01, + 1, то есть норм. вид 1.01
        #е = -3 < 0 => сдвиг был влево на 3 => 0.00101 

    float_number = integer_part_decimal + fractional_part_decimal

    if is_negative == True:
        return -float_number
    else:
        return float_number
    
#перевод из двоичного кода в десятичный дробной части числаы
def dec_to_bin_fractional(fractional_part: str):
    decimal_fraction = 0.0
    for i in range(len(fractional_part)):
        bit = int(fractional_part[i]) #i-тый бит дробной части
        decimal_fraction += bit * (2 ** -(i + 1)) #суммируем каждый бит помноженный на степень двойки
    return decimal_fraction

#ex: 11000000
# 1*2^(-1) + 1*2^(-2) + 0*2^(-3)... = 1/2 + 1/4 + 0... = 0.75