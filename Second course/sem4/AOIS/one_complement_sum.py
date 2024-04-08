def one_complement_sum(first_num: str, second_num: str):

    summary = ''
    carry = 0
    for first_bit, second_bit in zip(first_num[::-1], second_num[::-1]):
        result = int(first_bit) + int(second_bit) + carry
        if result == 2:
            summary = '0' + summary
            carry = 1
        elif result == 3:
            summary = '1' + summary
            carry = 1  
        else: 
            summary = str(result) + summary
            carry = 0
    
    if carry == 1:
        result = ''
        for bit in summary[::-1]:
            if bit == '0' and carry == 1:
                result = '1' + result
                carry = 0
            elif bit == '1' and carry == 1:
                result = '0' + result
            else:
                result = bit + result
        summary = result

    if len(summary) > 32:
        summary = summary[-32:]

    return summary


