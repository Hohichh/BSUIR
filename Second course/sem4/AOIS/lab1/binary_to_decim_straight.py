#перевод из двоичного кода в десятичный
def int_bin_to_dec_str(binary_number: str):
    #обработка знака
    is_negative = False
    if binary_number[0] == '1':
        is_negative = True
        binary_number = '0' + binary_number[1:]

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
