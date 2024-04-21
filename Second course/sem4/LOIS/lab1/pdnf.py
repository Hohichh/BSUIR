"""
Лабораторная работа № 1 по ЛОИС
Вариант 9 (Построение СДНФ)
Выполнили Веркович Е. В., Лукашевич А. Д.
Дата выполнения 20.04.2024
"""
import itertools
from logical_formula import LogicalFormula


class PDNF(object):
    def __init__(self, classic_formula: str = "0"):
        #инициализируем поле self.__pdnf
        self.__pdnf = PDNF.__form_pdnf(classic_formula)

    @staticmethod
    #метод для формирования сднф
    def __form_pdnf(classic_formula: str) -> str:
        formula = LogicalFormula(classic_formula)
        result_parts = list()
        #если в формуле нет переменных - сднф не составляется
        atomics_names = formula.atomics 
        if len(atomics_names) == 0:
            return "No atomics -- no pdnf"
        #формируем список комбиниаций значений атомарных формул.
        #Функция itertools.product генерирует декартово произведение
        #[True, False] с самим собой repeat=len(atomics_names) раз.
        combinations = list(itertools.product([True, False], repeat=len(atomics_names)))
        #в результате получаем список кортежей размером repeat
        for combination in combinations:
            #формируем словарь, где в соответсвие атом. формуле ставим её значение
            atomic_values = dict(zip(atomics_names, combination))
            #если результат формулы истина - формируем конъюкцию для данного набора значений
            if formula.get_result(atomic_values):
                result_parts.append(PDNF.__form_pdnf_part(atomic_values))
        #из списка конъюкций, формируем дизъюнкции
        result = PDNF.__combine_formula_from_parts(result_parts, "\\/")
        return result if len(result_parts) > 0 else "No true results -- np pdnf"

    @staticmethod
    #Формирует часть приведённой дизъюнктивной нормальной формы (ПДНФ) 
    #на основе значений атомарных переменных.
    def __form_pdnf_part(atomic_values: dict) -> str:
        result_parts = list()
        for atomic_name in atomic_values:
            if atomic_values[atomic_name]:
                # Если значение переменной истинно, добавляем имя переменной в список
                result_parts.append(atomic_name)
            else:
                # Если значение переменной ложно, добавляем отрицание имени переменной в список
                result_parts.append("(!" + atomic_name + ")")
        result = PDNF.__combine_formula_from_parts(result_parts, "/\\")
        return result

    @staticmethod
    #функция для формирования строки из частей формулы с заданным оператором(connecter)
    def __combine_formula_from_parts(formula_parts: list, connector: str) -> str:
        parts = formula_parts.copy()
        while len(parts) >= 2:
            # Извлечение первой части из списка и сохранение в буфер
            buf_part = parts.pop(0)
            #Объединение буферной части и остальной части формулы 
            parts[0] = f"({buf_part}{connector}{parts[0]})"

        return parts[0] if len(parts) > 0 else ""

    def __str__(self) -> str:
        return self.__pdnf
