"""
Лабораторная работа № 1 по ЛОИС
Вариант 9 (Построение СДНФ)
Выполнили Веркович Е. В., Лукашевич А. Д.
Дата выполнения 20.04.2024
"""
import sys
from pdnf import PDNF
from validator import *

#функция-интерфейс для взаимодействия пользователя с программой
def process_formula():
    while True:
        #ввод формулы
        formula = input("Enter formula (max 8 variables): ")
        if formula == "stop":
            sys.exit(0)
        #если формула корректна    
        if validator(formula):
        #формируем СДНФ         
            form = PDNF(formula)
            print(f"\nPDNF: {form}")



if __name__ == "__main__":
    process_formula()


