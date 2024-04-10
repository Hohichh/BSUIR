from binary_to_decim_straight import int_bin_to_dec_str
from decim_to_binary_straight import int_straight_code

#сумма чисел с плавающей точкой(положительные)
def add_float_binary(bin1:str, bin2:str):
    #обработка сложения с 0
    if bin1 == '0'*32:
        return bin2
    elif bin2 == '0'*32:
        return bin1
    elif bin1 == bin2 == '0'*32:
        return '0'*32
    
    #выдеяем последовательности битов для экспоненты и мантиссы. Знаковые чисто по приколу, роли не играют
    sign1, sign2 = bin1[0], bin2[0]
    exp1, exp2 = bin1[1:9], bin2[1:9]
    mantissa1, mantissa2 = bin1[9:], bin2[9:]

    #находим порядки чисел, переводим в десятичный вид и избавляемся от сдвига
    exp1_decimal = int_bin_to_dec_str(exp1.zfill(32)) - 127 if exp1 != '0'*8 else 0
    exp2_decimal = int_bin_to_dec_str(exp2.zfill(32)) - 127 if exp2 != '0'*8 else 0
    
    #записываем мантиссы в нормализованном виде, добавив слева ведущую единицу
    mantissa1 = '1' + mantissa1
    mantissa2 = '1' + mantissa2
    exp_shift = 0
    #корректируем матниссы, если значения экспонент различно
    #если экспонента 1 числа меньше либо равна экспоненте второго:
    if exp1_decimal <= exp2_decimal:
        exp_shift = exp2_decimal - exp1_decimal #вычисляем разность
        mantissa1 = "0" * exp_shift + mantissa1 #сдвигаем мантиссу превого числа на exp_shift 
        mantissa1 = mantissa1[:-exp_shift] if exp_shift > 0 else mantissa1 #избавляемся от лишних символов слева после сдвига
        greater_exp = exp2_decimal #запоминаем большую экспоненту
    else: #аналогично, если первая экспонента больше второй
        exp_shift = exp1_decimal - exp2_decimal
        mantissa2 = "0" * exp_shift + mantissa2 #сдвинули вторую мантиссу
        mantissa2 = mantissa2[:-exp_shift] if exp_shift > 0 else mantissa2
        greater_exp = exp1_decimal
    
    #суммруем две мантиссы "в столбик"
    result_mantissa = mantiss_sum(mantissa1, mantissa2)    
    #вычисляем разность длин результирующей мантиссы и первой(можно и второй, они скорректированы)
    mantissa_shift = len(result_mantissa) - len(mantissa1)
    #сдвиг экспоненты результирующего числа равен большей экспоненте(из двух слагаемых чисел) и сдвигу в результате суммы
    result_exp_shift = greater_exp + mantissa_shift
    #избавляемся от переполнения если произошел сдвиг
    if result_exp_shift > 0:
        result_mantissa = result_mantissa[:-result_exp_shift]
    else:#иначе мантисса не изменяется
        result_mantissa = result_mantissa
    
    #экспоненту переводим в бинарный вид
    result_exp_bin = int_straight_code(result_exp_shift + 127)[24:] if result_exp_shift != 0 else '0'*8

    result = sign1 + result_exp_bin + result_mantissa[1:]
    return result

#просто сумма мантисс :Р
def mantiss_sum(mantiss1:str, mantiss2:str):
    summary = ''
    carry = 0
    for first_bit, second_bit in zip(mantiss1[::-1], mantiss2[::-1]):
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
    if carry == 1:
        summary = '1' + summary
    return summary