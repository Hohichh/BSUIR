from add_float_binary import *

print("1:")
bin1 = decim_to_binary_float(2.1)
print(bin1)
bin2 = decim_to_binary_float(4.6)
print(bin2)
print(binary_to_decim_float(bin1))
print(binary_to_decim_float(bin2))
result = add_float_binary(bin1, bin2)
print("Summary: ",result)
result = binary_to_decim_float(result)
print(result)
