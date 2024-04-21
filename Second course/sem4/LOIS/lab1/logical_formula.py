"""
Лабораторная работа № 1 по ЛОИС
Вариант 9 (Построение СДНФ)
Выполнили Веркович Е. В., Лукашевич А. Д.
Дата выполнения 20.04.2024
"""
#класс, представляющий собой логическую формулу
class LogicalFormula(object):
    def __init__(self, formula: str = "0"):
        #инициализируем поле self._formula  
        self._formula = formula
    #декоратор для получения формулы
    @property
    def formula(self) -> str:
        return self._formula
    #декоратор, формирующий и возвращающий список атомарных формул
    @property
    def atomics(self) -> list[str]:
        atomics = list()
        for char in self._formula:
            if (char < "A") or (char > "Z"):
                continue
            if char not in atomics:
                atomics.append(char)
        return atomics
    #метод для определения значения формулы с помощью подстановок
    @staticmethod
    def _solve(const_formula: str):
        #выполняем операции, пока результирующая формула больше 1
        while len(const_formula) > 1:
            const_formula = LogicalFormula._perform_ops(const_formula)

        return True if const_formula == "1" else False

    @staticmethod
    def _perform_ops(const_formula: str):
        #замняем подстроки с операциями в исходной формуле на значение рузультата каждой операции
        const_formula = LogicalFormula._solve_neg(const_formula)
        const_formula = LogicalFormula._solve_disj(const_formula)
        const_formula = LogicalFormula._solve_conj(const_formula)
        const_formula = LogicalFormula._solve_eq(const_formula)
        const_formula = LogicalFormula._solve_impl(const_formula)
        return const_formula

    @staticmethod
    def _solve_disj(formula):
        #вычиление результата дизъюнкции
        while formula.find('(0\\/0)') != -1:
            formula = formula.replace('(0\\/0)', '0')
        while formula.find('(1\\/0)') != -1:
            formula = formula.replace('(1\\/0)', '1')
        while formula.find('(0\\/1)') != -1:
            formula = formula.replace('(0\\/1)', '1')
        while formula.find('(1\\/1)') != -1:
            formula = formula.replace('(1\\/1)', '1')
        return formula

    @staticmethod
    def _solve_conj(formula):
        #вычиление результата конъюнкции
        while formula.find('(0/\\0)') != -1:
            formula = formula.replace('(0/\\0)', '0')
        while formula.find('(1/\\0)') != -1:
            formula = formula.replace('(1/\\0)', '0')
        while formula.find('(0/\\1)') != -1:
            formula = formula.replace('(0/\\1)', '0')
        while formula.find('(1/\\1)') != -1:
            formula = formula.replace('(1/\\1)', '1')
        return formula

    @staticmethod
    def _solve_eq(formula):
        #вычиление результата эквиваленции        
        while formula.find('(0~0)') != -1:
            formula = formula.replace('(0~0)', '1')
        while formula.find('(1~0)') != -1:
            formula = formula.replace('(1~0)', '0')
        while formula.find('(0~1)') != -1:
            formula = formula.replace('(0~1)', '0')
        while formula.find('(1~1)') != -1:
            formula = formula.replace('(1~1)', '1')
        return formula

    @staticmethod
    def _solve_impl(formula):
        #вычиление результата импликации 
        while formula.find('(0->0)') != -1:
            formula = formula.replace('(0->0)', '1')
        while formula.find('(1->0)') != -1:
            formula = formula.replace('(1->0)', '0')
        while formula.find('(0->1)') != -1:
            formula = formula.replace('(0->1)', '1')
        while formula.find('(1->1)') != -1:
            formula = formula.replace('(1->1)', '1')
        return formula

    @staticmethod
    def _solve_neg(formula):
        #вычиление результата отицания 
        while formula.find('(!0)') != -1:
            formula = formula.replace('(!0)', '1')
        while formula.find('(!1)') != -1:
            formula = formula.replace('(!1)', '0')
        return formula

    def get_result(self, atomics_values: dict) -> bool:
        #метод для получения значения всей формулы
        const_formula = self.formula
        #если в формуле есть атомарные формулы, то мы заменяем их значения
        if len(atomics_values) > 0:
            const_formula = self._value_substitution(atomics_values)
        return LogicalFormula._solve(const_formula)

    def _value_substitution(self, atomics_values: dict) -> str:
        const_formula = self.formula
        #заменяем в исходной формуле буквенные символы на 0 или 1
        for atomic_name in atomics_values:
            const_formula = const_formula.replace(atomic_name, str(int(atomics_values[atomic_name])))
        return const_formula

    def __str__(self) -> str:
        return self._formula
