# Модуль showreveven
## Метод белый ящик
### Тест №1
* Цель: проверить базовую работу функции при четном числе строк
* Тип: позитивный
* Входные данные: input1.txt
* Ожидаемый результат: output1.txt
### Тест №1
* Цель: проверить базовую работу функции при нечетном числе строк
* Тип: позитивный
* Входные данные: input5.txt
* Ожидаемый результат: output5.txt
### Тест №2
* Цель: проверить работу при отсутствии файла
* Тип: негативный
* Входные данные: txt = NULL
* Ожидаемый результат: получение ошибки
### Тест №3
* Цель: проверить работу при пустом файле
* Тип: негативный
* Входные данные: empty.txt
* Ожидаемый результат: получение ошибки

# Модуль mnlb
## Метод белый ящик
### Тест №1
* Цель: проверить базовую работу функции
* Тип: позитивный
* Входные данные: input2.txt, m 0 0
* Ожидаемый результат: output2.txt
### Тест №2
* Цель: проверить работу при отсутствии файла
* Тип: негативный
* Входные данные: txt = NULL
* Ожидаемый результат: получение ошибки
### Тест №3
* Цель: проверить работу при пустом файле
* Тип: негативный
* Входные данные: empty.txt
* Ожидаемый результат: получение ошибки
### Тест №3
* Цель: проверить работу при файле из одной строки
* Тип: негативный
* Входные данные: input3.txt, m 0 0
* Ожидаемый результат: получение ошибки
### Тест №4
* Цель: проверить работу при нахождении курсора на последней строке
* Тип: негативный
* Входные данные: input4.txt, m 4 0
* Ожидаемый результат: получение ошибки

# Модуль set_cursor
## Метод белый ящик
### Тест №2
* Цель: проверить базовую работу функции
* Тип: позитивный
* Входные данные: input6.txt, m 1 3
* Ожидаемый результат: output6.txt
### Тест №2
* Цель: получение ошибки при установлении курсора на неверную строку
* Тип: позитивный
* Входные данные: input6.txt, m 9999 0
* Ожидаемый результат: получение ошибки
### Тест №2
* Цель: получение ошибки при установлении курсора на неверный столбец
* Тип: позитивный
* Входные данные: input6.txt, m 0 9999
* Ожидаемый результат: получение ошибки

# Модуль p
## Метод белый ящик
### Тест №1
* Цель: проверить базовую работу функции
* Тип: позитивный
* Входные данные: input4.txt, line = 1, \*contents = "Huh"
* Ожидаемый результат: output4.txt
### Тест №2
* Цель: проверить базовую работу функции для первой строки
* Тип: позитивный
* Входные данные: input4.txt, line = 0, \*contents = "Huh"
* Ожидаемый результат: output7.txt
### Тест №3
* Цель: проверить базовую работу функции для последней строки
* Тип: позитивный
* Входные данные: input4.txt, line = 4, \*contents = "Huh"
* Ожидаемый результат: output8.txt
### Тест №4
* Цель: проверить работу при отсутствии файла
* Тип: негативный
* Входные данные: txt = NULL, line = 0, \*contents = "Huh"
* Ожидаемый результат: получение ошибки
### Тест №5
* Цель: проверить работу при пустом файле
* Тип: негативный
* Входные данные: empty.txt, line = 0, \*contents = "Huh"
* Ожидаемый результат: получение ошибки
### Тест №6
* Цель: проверить работу неверном значении строки
* Тип: негативный
* Входные данные: input4.txt, line = 9999, \*contents = "Huh"
* Ожидаемый результат: получение ошибки
### Тест №7
* Цель: проверить работу при неверном значении текста
* Тип: негативный
* Входные данные: input4.txt, line = 0, \*contents = NULL
* Ожидаемый результат: получение ошибки

# Модуль save
## Метод белый ящик
### Тест №1
* Цель: проверить базовую работу функции
* Тип: позитивный
* Входные данные: input6.txt
* Ожидаемый результат: input6.txt
### Тест №2
* Цель: проверить работу при пустом файле
* Тип: негативный
* Входные данные: empty.txt
* Ожидаемый результат: получение ошибки
### Тест №3
* Цель: проверить работу при отсутствии файла
* Тип: негативный
* Входные данные: txt = NULL
* Ожидаемый результат: получение ошибки
### Тест №4
* Цель: проверить вывод команды в случае ошибки чтения файла
* Тип: негативный
* Входные данные: input6.txt, \*filename="/"
* Ожидаемый результат: получение ошибки