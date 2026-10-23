# 1. Ввод текста
# input() читает всю строку целиком, включая пробелы
text = input("Введите текст: ")

# 2. Разбиение на слова
words = text.split()

# Переменные для хранения самого длинного слова и его длины
longest_word = ""
max_length = 0

# 3. Поиск самого длинного слова
# Цикл for перебирает каждое слово из списка words
for word in words:
    if len(word) > max_length:
        max_length = len(word)
        longest_word = word

# 4. Вывод результата
# Проверка на пустой текст
if max_length > 0:
    print(f"Самое длинное слово: {longest_word}")
else:
    print("Текст пуст или не содержит слов.")