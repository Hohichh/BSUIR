def int_bin_to_dec_one(binary_number):
    is_negative = False
    if binary_number[0] == '1':
        is_negative = True
        binary_number = ''.join('1' if bit == '0' else '0' for bit in binary_number)
    
    decim_number = 0

    power = len(binary_number) - 1
    for bit in binary_number:
        decim_number += int(bit) * 2 ** power
        power -= 1
    
    if is_negative:
        return -decim_number
    else: 
        return decim_number