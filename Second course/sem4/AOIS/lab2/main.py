from logical_formula.truth_table import TruthTable
from logical_formula.pcnf_pdnf import PCN_PDN_Formula
from logical_formula.numeric_formula import NumericFormula

# ts = r"(!(P→(P→(Q~Q))))"
# ts = r"((!(A∧B))~C)"
ts = r"(((!(A∧B))~C)∨(D∧E))"
# ts = r"(A∨B)"

t = TruthTable(ts)
# print(t.get_only_results())
print(t)

t = PCN_PDN_Formula(ts)
print(t)
t = NumericFormula(ts)
print(t)
