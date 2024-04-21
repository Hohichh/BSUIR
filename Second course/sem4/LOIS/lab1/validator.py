"""
Лабораторная работа № 1 по ЛОИС
Вариант 9 (Построение СДНФ)
Выполнили Веркович Е. В., Лукашевич А. Д.
Дата выполнения 20.04.2024
"""
from logical_formula import LogicalFormula
#функция для валидации ввода
def validator(input_str: str) -> bool:
    formula = LogicalFormula(input_str)
    #в формуле может содержать не больше 8 переменных
    if len(formula.atomics) > 8:
        print("Too much variables")
        return False
    #проверка соответствия формулы грамматике сокращённого языка логики высказываний
    return checkout(input_str)

def checkout(input_str: str) -> bool:
    length = len(input_str)
    if length == 0:
        return False
    #проверка для констант и атомарных формул
    if length == 1:
        return symbol_checkout(input_str)
    #проверка для сложных формул
    if length >= 4:
        return formula_checkout(input_str)
    return False


def symbol_checkout(symbol: str) -> bool:
    #корректно, если форула - константа(0 или 1) или заглавная буква латинского алфавита
    if (symbol == "0") or (symbol == "1"):
        return True
    if (symbol >= "A") and (symbol <= "Z"):
        return True
    return False


def formula_checkout(formula: str) -> bool:
    #проверка на наличие скобок
    if (formula[0] != "(") or (formula[-1] != ")"):
        return False
    #проверка для унарных формул
    if unary_checkout(formula[1:-1]):
        return True
    #проверка для бинарных формул
    return binary_checkout(formula[1:-1])


def unary_checkout(formula: str) -> bool:
    #если нет оператора отрицания - формула не унарная
    if formula[0] != "!":
        return False
    return checkout(formula[1:])


def binary_checkout(formula: str) -> bool:
    if len(formula) < 3:
        return False
    #переменная для контроля уровня вложенности в формуле
    level = 0
    for i in range(len(formula) - 1):
        if formula[i] == "(":
            level += 1
            continue
        if formula[i] == ")":
            level -= 1
            continue
        if level > 0:
            continue
        #при уровне вложенности равном 0, ищем бинарные операторы
        #делим строку на 2 части - до бинарного оператора и после - рекурсивно их проверяем
        if formula[i] == "~":
            return checkout(formula[:i]) and checkout(formula[i + 1:])
        if double_symbol_operator(formula[i:i+2]):
            return checkout(formula[:i]) and checkout(formula[i + 2:])
    return False


def double_symbol_operator(operator: str):
    #проверяем ялвяется ли
    return (operator == "\\/") or (operator == "/\\") or (operator == "->")
