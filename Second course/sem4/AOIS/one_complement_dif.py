from one_complement_sum import one_complement_sum

def one_complement_dif(first_num:str, second_num:str):
    difference = ''
    if second_num[0] == '0':
        second_num = ''.join('1' if bit == '0' else '0' for bit in second_num)
        difference = one_complement_sum(first_num, second_num)
    elif second_num[0] == '1':
        second_num = ''.join('1' if bit == '0' else '0' for bit in second_num)
        difference = one_complement_sum(first_num, second_num)
    return difference

