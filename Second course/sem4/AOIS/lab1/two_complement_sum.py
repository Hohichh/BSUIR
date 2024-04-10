#сложение чисел в дополнительном коде
def two_complement_sum(first_num: str, second_num:str):
    summary = ''
    carry = 0
    #складываем в столбик каждый бит одного числа с другим
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
    #при переполнении просто добавляем единицу в конец      
    if carry == 1:
        summary = '1' + summary
    if len(summary) > 32:
        summary = summary[-32:]

    return summary