#перевод из двоичного дополнительного кода в десятичный
def int_bin_to_dec_two(binary_number):
    is_negative = False
    #обработка знака: если первый бит - 1, то отнимает единицу и инвертируем биты числа
    if binary_number[0] == '1':
        is_negative = True

        carry = 1
        result = ''
        for bit in binary_number[::-1]:
            if bit == '1' and carry == 1:
                result = '0' + result
                carry = 0
            elif bit == '0' and carry == 1:
                result = '1' + result
            else:
                result = bit + result
        binary_number = result
        
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