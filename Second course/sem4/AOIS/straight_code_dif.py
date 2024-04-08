from straight_code_sum import straight_code_sum
from binary_to_decim_straight import int_bin_to_dec_str

def dif(first_num: str, second_num: str):
    result = ''
    borrow = 0
    for i in range(len(first_num)-1, -1, -1):
        diff = int(first_num[i]) - int(second_num[i]) - borrow
        if diff < 0:
            diff += 2
            borrow = 1
        else:
            borrow = 0
        result = str(diff) + result

    return result

def straight_code_dif(first_num: str, second_num:str):
    difference = ''

    if second_num[0] == '1':
        second_num = '0' + second_num[1:]
        difference = straight_code_sum(first_num, second_num)
    elif first_num[0] == '1':
        second_num = '1' + second_num[1:]
        difference = straight_code_sum(first_num, second_num)
    else:
        if abs(int_bin_to_dec_str(first_num)) >= abs(int_bin_to_dec_str(second_num)):
            difference = dif(first_num, second_num)
        else:
            difference = dif(second_num, first_num)
            difference = '1' + difference[1:]
    
    return difference


