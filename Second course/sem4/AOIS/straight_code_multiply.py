from two_complement_sum import two_complement_sum
from binary_to_decim_straight import int_bin_to_dec_str

def straight_multiply(first_num: str, second_num: str):
    first_sign = first_num[0]
    second_sign = second_num[0]

    result = '0' * 32

    first_num = first_num[1:]
    second_num = second_num[1:]
    
    for i in range(len(second_num) - 1, -1, -1):
        if second_num[i] == '1':
            term = first_num + '0' * (len(second_num) - i - 1)  
            result = two_complement_sum(result, term)

    if int_bin_to_dec_str(result) == 0:
        return '0' + result

    if first_sign != second_sign:
        return '1' + result[1:]  
    else:
        return '0' + result[1:]  






