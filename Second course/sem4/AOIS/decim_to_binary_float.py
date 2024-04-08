from decim_to_binary_straight import int_straight_code
#перевод дробной части в двоичную форму
def dec_to_bin_fractional(fractional_part: float):
    if fractional_part == 0:
        return '0' * 23
    result = 0
    fractional_bin = ''
    while True:
        result = fractional_part * 2
        fractional_part = result - int(result)
        fractional_bin += str(int(result))
        if fractional_part == 0:
            break
    return fractional_bin    


def decim_to_binary_float(decimal_number):
    if decimal_number == 0:
        return '0' * 32
    #определяем знаковый бит
    bin_sign = '1' if decimal_number < 0 else '0'

    decimal_number = abs(decimal_number)
    #выделяем целую и дробную часть
    integer_part_decimal = int(decimal_number)
    fractional_part_decimal = decimal_number - integer_part_decimal
    #перевод дробной и целой части в двоичный код и корректировка длины строк
    integer_part_binary = int_straight_code(integer_part_decimal)
    integer_part_binary = '0' if integer_part_binary == '0'*32 else integer_part_binary.lstrip('0')

    fractional_part_binary = dec_to_bin_fractional(fractional_part_decimal)
    total_length = len(integer_part_binary) + len(fractional_part_binary)

    if total_length > 23:
        excess_length = total_length - 23
        fractional_part_binary = fractional_part_binary[:-excess_length]
    #-------------------------------------------------------------------

    exponent = 0
    mantissa = ''
    #"нормализуем" чтобы мантисса была [1, 2) и определяем экспоненту со сдвигом
    if integer_part_binary == '0':
        exponent = -(len(fractional_part_binary) - len(fractional_part_binary.lstrip('0')) + 1)
        exponent_shift = exponent + 127
        mantissa = fractional_part_binary[-exponent - 1:]
        #ex:
        #0.00101(2) => 1.01 -- 1 - доп единица, которая не хранится, в мантиссу запишется 01
        #сдвинули на 3 знака вправо => е(10) = -3 или 124   
    else:
        exponent_shift = (len(integer_part_binary) - 1) + 127
        mantissa = integer_part_binary + fractional_part_binary
        #ex:
        #100.01(2) => 1.0001 - 1 доп. еденица, в мантиссу запишется 0001
        #сдвинули точку на 2 знака вправо => е(10) = 2 или 129

    exponent_shift = int_straight_code(exponent_shift)[24:]
    mantissa = mantissa[1:].ljust(23, '0')

    return bin_sign + exponent_shift + mantissa

