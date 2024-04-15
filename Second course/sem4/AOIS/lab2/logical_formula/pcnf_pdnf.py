import pandas as pd

from logical_formula.truth_table import TruthTable


class PCN_PDN_Formula(object):
    def __init__(self, formula: str):
        self.raw_formula = formula
        self.value_table = TruthTable(formula).get_short_result()
        self.conjunction_form = self.__form_conjunction_form()
        self.disjunction_form = self.__form_disjunction_form()

    def __form_one_conjunction_part(self, part: pd.Series) -> str:
        result = "("
        for index in range(len(part)):
            if index == len(part) - 1:
                result = result[:-1]
                break
            if part.iloc[index]:
                result += "(!" + self.value_table.columns[index] + ")∨"
            else:
                result += self.value_table.columns[index] + "∨"
        result += ")∧"
        return result

    def __form_conjunction_form(self) -> str:
        result = ""
        formulas_counter = 0
        for index, line in self.value_table.iterrows():
            if line.iloc[-1]:
                continue
            formulas_counter += 1
            result += self.__form_one_conjunction_part(line)

        if len(result) > 0:
            result = result[:-1]

        if formulas_counter > 1:
            result = "(" + result + ")"

        return result + "\n"

    def __form_one_disjunction_part(self, part: pd.Series) -> str:
        result = "("
        # print(len(part))
        for index in range(len(part)):
            if index == len(part) - 1:
                result = result[:-1]
                break
            if part.iloc[index]:
                # print(self.value_table.columns[index])
                result += self.value_table.columns[index] + "∧"
            else:
                result += "(!" + self.value_table.columns[index] + ")∧"
        result += ")∨"
        return result

    def __form_disjunction_form(self) -> str:
        result = ""
        formulas_counter = 0
        for index, line in self.value_table.iterrows():
            if not line.iloc[-1]:
                continue
            formulas_counter += 1
            result += self.__form_one_disjunction_part(line)

        if len(result) > 0:
            result = result[:-1]

        if formulas_counter > 1:
            result = "(" + result + ")"

        return result

    def __str__(self):
        return "Conjunction form: " + self.conjunction_form + "Disjunction form: " + self.disjunction_form