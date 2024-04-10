from binary_to_decim_straight import int_bin_to_dec_str

#деление чисел в прямом коде
def straight_code_devision(first_num: str, second_num: str):
    result = ''
    #обработка ситуаций типа x/0 и 0/х
    if int_bin_to_dec_str(second_num) == 0:
        raise ZeroDivisionError("Devider equals zero!")
    if int_bin_to_dec_str(first_num) == 0:
        return first_num

    first_sign = first_num[0]
    second_sign = second_num[0]
    #убираем знаковые биты
    first_num = first_num[1:]
    second_num = second_num[1:]
    #удаляем лишние нули в строке слева
    first_num = first_num.lstrip('0')
    second_num = second_num.lstrip('0')

    substr = ''
    remainder = ''
    i = 0
    #типа делим в столбик
    while i <= len(first_num):
        if i == 0:
            substr = first_num[:len(second_num)] #на первой итерации выделили подстрочку
            i = len(second_num) #ставим i на следующий бит после подстроки

        if greater(substr, second_num) == True: #если число в подстроке больше делителя
            result = result + '1' #в результате 1
            remainder = dif(substr, second_num) #вычитаем из подстроки делитель
            if i < len(first_num):
                remainder = remainder + first_num[i] #приписываем к остатку символ после подстроки
        else:
            result = result + '0' #если число в подстроке миньше делителя  - 0 в результат
            if i < len(first_num):
                remainder = substr + first_num[i] #приписываем символ после подстроки 
        
        remainder = remainder.lstrip('0')
        if remainder == '':
            remainder = '0'
        substr = remainder
        i += 1

    result = result.zfill(32)

    if first_sign != second_sign:
        return '1' + result[1:]  
    else:
        return '0' + result[1:] 
    
#функция для сравения остатка(подстроки) из делимого и делителя
def greater(first_num: str, second_num: str) -> bool:
    first_num = first_num.zfill(32)
    second_num = second_num.zfill(32)
    return first_num >= second_num    

#разность остатка(подстроки) и делителя
def dif(first_num: str, second_num: str):
    result = ''
    borrow = 0
    if len(second_num) < len(first_num):
        second_num = second_num.zfill(len(first_num))

    for i in range(len(first_num)-1, -1, -1):
        diff = int(first_num[i]) - int(second_num[i]) - borrow
        if diff < 0:
            diff += 2
            borrow = 1
        else:
            borrow = 0
        result = str(diff) + result

    return result