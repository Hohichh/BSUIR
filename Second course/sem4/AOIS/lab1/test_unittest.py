from my_imports import *
import unittest   # The test framework

class Test_ConverterInteger(unittest.TestCase):
    def setUp(self):
        self.pos_int = 87
        self.neg_int = -14
        self.zero_int = 0
    
    def test_straight_code(self):
        bin_pos = int_straight_code(self.pos_int)
        bin_neg = int_straight_code(self.neg_int)
        bin_zero = int_straight_code(self.zero_int)
        self.assertEqual(bin_pos, '00000000000000000000000001010111')
        self.assertEqual(bin_neg, '10000000000000000000000000001110')
        self.assertEqual(bin_zero, '00000000000000000000000000000000')

        self.assertEqual(int_bin_to_dec_str(bin_pos), 87)
        self.assertEqual(int_bin_to_dec_str(bin_neg), -14)
        self.assertEqual(int_bin_to_dec_str(bin_zero), 0)
    
    def test_one_complement_code(self):
        bin_pos = int_one_complement(self.pos_int)
        bin_neg = int_one_complement(self.neg_int)
        bin_zero = int_one_complement(self.zero_int)
        self.assertEqual(bin_pos, '00000000000000000000000001010111')
        self.assertEqual(bin_neg, '11111111111111111111111111110001')
        self.assertEqual(bin_zero, '00000000000000000000000000000000')

        self.assertEqual(int_bin_to_dec_one(bin_pos), 87)
        self.assertEqual(int_bin_to_dec_one(bin_neg), -14)
        self.assertEqual(int_bin_to_dec_one(bin_zero), 0)   

    def test_two_complement_code(self):
        bin_pos = int_two_complement(self.pos_int)
        bin_neg = int_two_complement(self.neg_int)
        bin_zero = int_two_complement(self.zero_int)
        self.assertEqual(bin_pos, '00000000000000000000000001010111')
        self.assertEqual(bin_neg, '11111111111111111111111111110010')
        self.assertEqual(bin_zero, '00000000000000000000000000000000')

        self.assertEqual(int_bin_to_dec_two(bin_pos), 87)
        self.assertEqual(int_bin_to_dec_two(bin_neg), -14)
        self.assertEqual(int_bin_to_dec_two(bin_zero), 0)   

class Test_SummaryIntegerStraight(unittest.TestCase):
    def test_pos_pos(self):
        first_num = int_straight_code(23)
        second_num = int_straight_code(41)
        result = int_bin_to_dec_str(straight_code_sum(first_num, second_num))
        self.assertEqual(result, 64)
        

    def test_pos_neg(self):
        first_num = int_straight_code(106)
        second_num = int_straight_code(-7)
        result = int_bin_to_dec_str(straight_code_sum(first_num, second_num))
        self.assertEqual(result, 99)

    def test_neg_pos(self):
        first_num = int_straight_code(-87)
        second_num = int_straight_code(9)
        result = int_bin_to_dec_str(straight_code_sum(first_num, second_num))
        self.assertEqual(result, -78)

    def test_neg_neg(self):
        first_num = int_straight_code(-10)
        second_num = int_straight_code(-7)
        result = int_bin_to_dec_str(straight_code_sum(first_num, second_num))
        self.assertEqual(result, -17)

class Test_DifferenceInteger(unittest.TestCase):
    def test_pos_pos(self):
        pass

    def test_pos_neg(self):
        pass

    def test_neg_pos(self):
        pass

    def test_neg_neg(self):
        pass

class Test_MultiplyInteger(unittest.TestCase):
    def test_pos_pos(self):
        pass

    def test_pos_neg(self):
        pass

    def test_neg_pos(self):
        pass

    def test_neg_neg(self):
        pass

class Test_DivideInteger(unittest.TestCase):
    def test_pos_pos(self):
        pass

    def test_pos_neg(self):
        pass

    def test_neg_pos(self):
        pass

    def test_neg_neg(self):
        pass

class Test_SummaryFloat(unittest.TestCase):
    def test_pos_pos(self):
        pass

    def test_pos_neg(self):
        pass

    def test_neg_pos(self):
        pass

    def test_neg_neg(self):
        pass

if __name__ == '__main__':
    unittest.main()