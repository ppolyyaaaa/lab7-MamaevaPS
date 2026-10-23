#include <iostream>
#include <string>
#include <sstream>
#include <windows.h> // Для Windows (UTF-8)

int countWords(const std::string& text) {
    std::istringstream iss(text);
    std::string word;
    int count = 0;
    
    // Оператор >> автоматически пропускает пробелы и считывает слова
    while (iss >> word) {
        ++count;
    }
    
    return count;
}

int main() {
    // Включаем поддержку UTF-8 для корректного ввода/вывода кириллицы в Windows
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    std::string text;
    std::cout << "Введите текст: ";
    
    // Используем getline, чтобы захватить всю строку вместе с пробелами
    std::getline(std::cin, text);

    std::cout << "Количество слов: " << countWords(text) << "\n";

    return 0;
}
