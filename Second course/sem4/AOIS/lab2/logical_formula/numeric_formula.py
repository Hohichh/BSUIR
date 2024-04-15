from logical_formula.truth_table import TruthTable

class NumericFormula(object):
    def __init__(self, formula: str):
        self.value_table = TruthTable(formula).get_short_result()
        self.numeric_list = self.__create_numeric_list()
        self.pcnf_numeric = self.__create_pcnf_numeric()
        self.pdnf_numeric = self.__create_pdnf_numeric()
        self.index_form = self.__compute_index_form()

    def __create_numeric_list(self):
        numeric_list = self.value_table.copy()
        numeric_list.reset_index(drop=True, inplace=True)
        return numeric_list.reset_index()

    def __create_pcnf_numeric(self):
        return list(self.numeric_list[self.numeric_list.iloc[:, -1] == True]['index'])

    def __create_pdnf_numeric(self):
        return list(self.numeric_list[self.numeric_list.iloc[:, -1] == False]['index'])

    def __compute_index_form(self):
        total_rows = len(self.value_table)
        index_form = 0
        for num in self.pcnf_numeric:
            index_form += 2 ** (total_rows - num - 1)
        return index_form

    def __str__(self):
        numeric_str = "Numeric List:\n"
        numeric_str += self.numeric_list.to_string(index=False) + "\n"
        numeric_str += f"\nPCNF Numeric: {self.pcnf_numeric}"
        numeric_str += f"\nPDNF Numeric: {self.pdnf_numeric}"
        numeric_str += f"\n i = {self.index_form}"
        return numeric_str
