#перевод из обратного двоичного кода в десятичныйы
def int_bin_to_dec_one(binary_number):
    #обработка знака: если первый бит - 1, то инвертируем биты числа
    is_negative = False
    if binary_number[0] == '1':
        is_negative = True
        binary_number = ''.join('1' if bit == '0' else '0' for bit in binary_number)
    
    decim_number = 0
    #перевод в десятичный вид: скдадываем каждый бит, помноженный на степень 2-ки
    power = len(binary_number) - 1
    for bit in binary_number:
        decim_number += int(bit) * 2 ** power
        power -= 1
    
    if is_negative:
        return -decim_number
    else: 
        return decim_number