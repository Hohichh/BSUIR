from decim_to_binary_float import decim_to_binary_float
from binary_to_decim_float import binary_to_decim_float

def add_float_binary(bin_num1, bin_num2):
    # Получение знака, экспоненты и мантиссы для каждого числа
    sign1 = int(bin_num1[0])
    sign2 = int(bin_num2[0])
    exponent1 = int(bin_num1[1:9], 2) - 127
    exponent2 = int(bin_num2[1:9], 2) - 127
    mantissa1 = '1' + bin_num1[9:]  # Добавляем нормализованную единицу в мантиссу
    mantissa2 = '1' + bin_num2[9:]

    # Нормализация мантисс
    mantissa1 = mantissa1.ljust(24, '0')  # Дополняем мантиссу до 24 бит нулями
    mantissa2 = mantissa2.ljust(24, '0')

    # Определение смещения экспоненты для выравнивания
    shift_amount = abs(exponent1 - exponent2)
    if exponent1 > exponent2:
        mantissa2 = mantissa2[:23 - shift_amount] + '0' * shift_amount
        exponent = exponent1
    else:
        mantissa1 = mantissa1[:23 - shift_amount] + '0' * shift_amount
        exponent = exponent2

    # Сложение мантисс с учетом знаков
    if sign1 == sign2:
        result_mantissa = bin(int(mantissa1, 2) + int(mantissa2, 2))[2:]
    else:
        result_mantissa = bin(int(mantissa1, 2) - int(mantissa2, 2))[2:]

    # Нормализация результата
    if len(result_mantissa) > 24:  # Обработка переполнения мантиссы
        exponent += 1
        result_mantissa = result_mantissa[1:]

    # Формирование результата в формате IEEE-754
    result_sign = 0 if result_mantissa[0] == '0' else 1
    result_exponent = format(exponent + 127, '08b')
    result_mantissa = result_mantissa[1:24]  # Обрезаем мантиссу до 23 бит
    result = str(result_sign) + result_exponent + result_mantissa

    return result


bin1 = decim_to_binary_float(7.75)
print(bin1)
bin2 = decim_to_binary_float(4.0)
print(bin2)
print(binary_to_decim_float(bin1))
print(binary_to_decim_float(bin2))
result = add_float_binary(bin1, bin2)
print("Summary: ",result)
result = binary_to_decim_float(result)
print(result)