def int_straight_code(decimal_number):
    if decimal_number == 0:
        return '0'*32
    
    is_negative = False
    if decimal_number < 0:
        is_negative = True
        decimal_number = abs(decimal_number)

    binary_number = ''
    while decimal_number > 0:
        remainder = decimal_number % 2
        binary_number = str(remainder) + binary_number
        decimal_number //= 2

    binary_number = binary_number.rjust(32, '0')

    if is_negative:
        binary_number = '1' + binary_number[1:]

    return binary_number



