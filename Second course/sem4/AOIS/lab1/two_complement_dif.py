from two_complement_sum import two_complement_sum
#разность чисел в дополнительном коде
def two_complement_dif(first_num: str, second_num:str):
    #инвертируем биты второго числа
    inverted_second_number = ''.join('1' if bit == '0' else '0' for bit in second_num)
    #добавляем единицу
    carry = 1
    result = ''
    for bit in inverted_second_number[::-1]:
        if bit == '0' and carry == 1:
            result = '1' + result
            carry = 0
        elif bit == '1' and carry == 1:
            result = '0' + result
        else:
            result = bit + result
    if carry == 1:
        result = '1' + result
    #скалдываем превое число и модифицированное второе
    difference = two_complement_sum(first_num, result)

    return difference