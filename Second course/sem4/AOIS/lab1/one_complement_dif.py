from one_complement_sum import one_complement_sum
#разность чисел в обратном коде
def one_complement_dif(first_num:str, second_num:str):
    difference = ''
    second_num = ''.join('1' if bit == '0' else '0' for bit in second_num) #инвертируем биты
    difference = one_complement_sum(first_num, second_num) #суммируем 
    return difference

    