from my_imports import *

print("Simulator of representation of numbers in computer memory")

while True:
    print('''\nSelect operation:
          1 -- Convert from decimal to binary (integer)
          2 -- Sum of two numbers
          3 -- Difference of two numbers 
          4 -- Multiply 2 numbers in straight code
          5 -- Divide 2 numbers in straight code
          6 -- Add 2 positive floating point numbers 
          7 -- Exit
          ''')
    
    choise = input("\nOperation: ")
    match choise:
        case '1':
            num = int(input("\nEnter a num: "))
            print(f"\nUr number: {num}")
            print(f"\nStraight code: {int_straight_code(num)}")
            print(f"Check: {int_bin_to_dec_str(int_straight_code(num))}")

            print(f"\nOne's complement code: {int_one_complement(num)}")
            print(f"Check: {int_bin_to_dec_one(int_one_complement(num))}")

            print(f"\nTwo's complement code: {int_two_complement(num)}")
            print(f"Check: {int_bin_to_dec_two(int_two_complement(num))}")
        case '2':
            first_num = int(input("\nEnter the first num: "))
            second_num = int(input("\nEnter the second num: "))
            
            print("\nStraight code: ")
            bin_fisrt = int_straight_code(first_num)
            bin_second = int_straight_code(second_num)
            print(f'{bin_fisrt} + {bin_second} = ')
            summary = straight_code_sum(bin_fisrt, bin_second)
            print(summary)
            print(f"Check: {int_bin_to_dec_str(summary)}")

            print("\nOne's complement code: ")
            bin_fisrt = int_one_complement(first_num)
            bin_second = int_one_complement(second_num)
            print(f'{bin_fisrt} + {bin_second} = ')
            summary = one_complement_sum(bin_fisrt, bin_second)
            print(summary)
            print(f"Check: {int_bin_to_dec_one(summary)}")

            print("\nTwo's complement code: ")
            bin_fisrt = int_two_complement(first_num)
            bin_second = int_two_complement(second_num)
            print(f'{bin_fisrt} + {bin_second} = ')
            summary = two_complement_sum(bin_fisrt, bin_second)
            print(summary)
            print(f"Check: {int_bin_to_dec_two(summary)}")
        case '3':
            first_num = int(input("\nEnter the first num: "))
            second_num = int(input("\nEnter the second num: "))

            print("\nStraight code: ")
            bin_fisrt = int_straight_code(first_num)
            bin_second = int_straight_code(second_num)
            print(f'{bin_fisrt} - {bin_second} = ')
            difference = straight_code_dif(bin_fisrt, bin_second)
            print(difference)
            print(f"Check: {int_bin_to_dec_str(difference)}")

            print("\nOne's complement code: ")
            bin_fisrt = int_one_complement(first_num)
            bin_second = int_one_complement(second_num)
            print(f'{bin_fisrt} - {bin_second} = ')
            difference = one_complement_dif(bin_fisrt, bin_second)
            print(difference)
            print(f"Check: {int_bin_to_dec_one(difference)}")

            print("\nTwo's complement code: ")
            bin_fisrt = int_two_complement(first_num)
            bin_second = int_two_complement(second_num)
            print(f'{bin_fisrt} - {bin_second} = ')
            difference = two_complement_dif(bin_fisrt, bin_second)
            print(difference)
            print(f"Check: {int_bin_to_dec_two(difference)}")
        case '4':
            first_num = int(input("\nEnter the first num: "))
            second_num = int(input("\nEnter the second num: "))
            bin_fisrt = int_straight_code(first_num)
            bin_second = int_straight_code(second_num)
            print(f'{bin_fisrt} * {bin_second} = ')
            multiply = straight_multiply(bin_fisrt, bin_second)
            print(multiply)
            print(f"Check: {int_bin_to_dec_str(multiply)}")
        case '5':
            first_num = int(input("\nEnter the first num: "))
            second_num = int(input("\nEnter the second num: "))
            bin_fisrt = int_straight_code(first_num)
            bin_second = int_straight_code(second_num)
            print(f'{bin_fisrt} / {bin_second} = ')
            try:
                division = straight_code_devision(bin_fisrt, bin_second)
                print(division)
                print(f"Check: {int_bin_to_dec_str(division)}")
            except ZeroDivisionError as e:
                print(e)
        case '6':
            break
        case '7':
            break
        case _:
            print("Enter a number from 1 to 7!")