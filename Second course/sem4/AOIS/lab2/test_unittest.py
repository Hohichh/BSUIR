import unittest  
import pandas as pd
from logical_formula.logical_formula import LogicalFormula
from logical_formula.nodes import *
from logical_formula.truth_table import TruthTable
from logical_formula.pcnf_pdnf import PCN_PDN_Formula
from logical_formula.numeric_formula import NumericFormula

class TestLogicalFormula(unittest.TestCase):

    def test_convert_const(self):
        formula = LogicalFormula()
        convert_const_method = getattr(formula, "_LogicalFormula__convert_const")
        self.assertTrue(isinstance(convert_const_method("1"), TrueNode))
        self.assertTrue(isinstance(convert_const_method("0"), FalseNode))

    def test_convert_atomic(self):
        formula = LogicalFormula()
        convert_atomic_method = getattr(formula, "_LogicalFormula__convert_atomic")
        self.assertTrue(isinstance(convert_atomic_method("A"), Atomic))
        self.assertEqual(formula._atomics["A"]._name, "A")

    def test_convert_unary(self):
        formula = LogicalFormula()
        convert_unary_method = getattr(formula, "_LogicalFormula__convert_unary")
        node = convert_unary_method("(!A)")
        self.assertTrue(isinstance(node, Negation))
        self.assertEqual(node._operand._name, "A")

    def test_parse_binary_logical_expression(self):
        formula = LogicalFormula()
        parse_method = getattr(formula, "_LogicalFormula__parse_binary_logical_expression")
        node = parse_method("(A∧B)", 2)
        self.assertTrue(isinstance(node, Conjunction))
        self.assertEqual(node.left_op._name, "A")
        self.assertEqual(node.right_op._name, "B")

    def test_convert_binary(self):
        formula = LogicalFormula()
        convert_binary_method = getattr(formula, "_LogicalFormula__convert_binary")
        node = convert_binary_method("(A∨B)")
        self.assertTrue(isinstance(node, Disjunction))
        self.assertEqual(node.left_op._name, "A")
        self.assertEqual(node.right_op._name, "B")

    def test_convert(self):
        formula = LogicalFormula()
        convert_method = getattr(formula, "_LogicalFormula__convert")
        node = convert_method("(A→B)")
        self.assertTrue(isinstance(node, Implication))
        self.assertEqual(node.left_op._name, "A")
        self.assertEqual(node.right_op._name, "B")

    def test_switch(self):
        formula = LogicalFormula("(A∧B)")
        switch_method = getattr(formula, "switch")
        switch_method("A")
        self.assertEqual(formula.get_result(), False)

class TestTruthTable(unittest.TestCase):

    def test_get_short_result(self):
        formula = "(A∧B)"
        table = TruthTable(formula).get_short_result()
        expected_columns = ["A", "B", "(A∧B)"]
        self.assertListEqual(list(table.columns), expected_columns)
        self.assertEqual(table.shape[0], 4)

    def test_get_only_results(self):
        formula = "(A∧B)"
        results = TruthTable(formula).get_only_results()
        expected_results = [False, False, True, False]
        self.assertListEqual(results, expected_results)

class TestPCN_PDN_Formula(unittest.TestCase):

    def test_form_one_conjunction_part(self):
        formula = "(A∧B)"
        obj = PCN_PDN_Formula(formula)
        part = obj.value_table.iloc[0]
        result = obj._PCN_PDN_Formula__form_one_conjunction_part(part)
        expected_result = "(A∨B)∧"
        self.assertEqual(result, expected_result)

    def test_form_conjunction_form(self):
        formula = "(A∧B)"
        obj = PCN_PDN_Formula(formula)
        result = obj._PCN_PDN_Formula__form_conjunction_form()
        expected_result = "((A∨B)∧((!A)∨B)∧(A∨(!B)))\n"
        self.assertEqual(result, expected_result)

    def test_form_one_disjunction_part(self):
        formula = "(A∧B)"
        obj = PCN_PDN_Formula(formula)
        part = obj.value_table.iloc[3]
        result = obj._PCN_PDN_Formula__form_one_disjunction_part(part)
        expected_result = "((!A)∧B)∨"
        self.assertEqual(result, expected_result)

    def test_form_disjunction_form(self):
        formula = "(A∧B)"
        obj = PCN_PDN_Formula(formula)
        result = obj._PCN_PDN_Formula__form_disjunction_form()
        expected_result = "(A∧B)"
        self.assertEqual(result, expected_result)

    def test_str(self):
        formula = "(A∧B)"
        obj = PCN_PDN_Formula(formula)
        result_str = str(obj)
        expected_str = "Conjunction form: ((A∨B)∧((!A)∨B)∧(A∨(!B)))\nDisjunction form: (A∧B)"
        self.assertEqual(result_str, expected_str)

class TestNumericFormula(unittest.TestCase):

    def test_create_numeric_list(self):
        formula = "(A∧B)"
        obj = NumericFormula(formula)
        result = obj.value_table
        expected_result = pd.DataFrame({
            "A": [False, True, True, False],
            "B": [False, False, True, True],
            "(A∧B)": [False, False, True, False],
            "index": [0, 1, 2, 3]
        })
        result["index"] = obj.numeric_list["index"]
        pd.testing.assert_frame_equal(result, expected_result)

    def test_create_pcnf_numeric(self):
        formula = "(A∧B)"
        obj = NumericFormula(formula)
        result = obj.pcnf_numeric
        expected_result = [2]
        self.assertEqual(result, expected_result)

    def test_create_pdnf_numeric(self):
        formula = "(A∧B)"
        obj = NumericFormula(formula)
        result = obj.pdnf_numeric
        expected_result = [0, 1, 3]
        self.assertEqual(result, expected_result)

    def test_compute_index_form(self):
        formula = "(A∧B)"
        obj = NumericFormula(formula)
        result = obj.index_form
        expected_result = 2
        self.assertEqual(result, expected_result)


if __name__ == '__main__':
    unittest.main()