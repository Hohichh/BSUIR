def int_bin_to_dec_str(binary_number: str):
    is_negative = False
    if binary_number[0] == '1':
        is_negative = True
        binary_number = '0' + binary_number[1:]

    decim_number = 0

    power = len(binary_number) - 1
    for bit in binary_number:
        decim_number += int(bit) * 2 ** power
        power -= 1
    
    if is_negative:
        return -decim_number
    else: 
        return decim_number
