#include <iostream>
#include <string>
#include <sstream>
#include <windows.h> // Для работы с консолью Windows

int main() {
    // Включаем поддержку UTF-8 для ввода и вывода в консоли Windows
    #ifdef _WIN32
        SetConsoleCP(CP_UTF8);       // Для корректного ВВОДА (std::cin)
        SetConsoleOutputCP(CP_UTF8); // Для корректного ВЫВОДА (std::cout)
    #endif

    // 1. Ввод текста
    std::string text;
    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    // 2. Разбиение на слова
    std::istringstream iss(text);
    std::string word;

    // Переменные для хранения самого длинного слова и его длины
    std::string longest_word = "";
    int max_length = 0;

    // 3. Поиск самого длинного слова
    while (iss >> word) {
        // Если длина текущего слова больше максимальной, запоминаем его
        if (word.length() > max_length) {
            max_length = word.length();
            longest_word = word;
        }
    }

    // 4. Вывод результата
    if (max_length > 0) {
        std::cout << "Самое длинное слово: " << longest_word << "\n";
    } else {
        std::cout << "Текст пуст или не содержит слов.\n";
    }

    return 0;
}
