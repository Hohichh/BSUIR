#перевод числа в обратный двоичный код
def int_one_complement(decimal_number):
    if decimal_number == 0:
        return '0'*32
    #обработка знака числа 
    is_negative = False
    if decimal_number < 0:
        is_negative = True
        decimal_number = abs(decimal_number)
    #перевод в прямой код: делим число на 2, остаток 0 или 1 записываем в binary_number
    binary_number = ''
    while decimal_number > 0:
        remainder = decimal_number % 2
        binary_number = str(remainder) + binary_number
        decimal_number //= 2
    #справа дополняем строку нулями, чтобы соблюдать 32-битное представление
    binary_number = binary_number.rjust(32, '0')
    #если число отрицательное - инвертируем биты
    if is_negative:
        binary_number = ''.join('1' if bit == '0' else '0' for bit in binary_number)

    return binary_number

