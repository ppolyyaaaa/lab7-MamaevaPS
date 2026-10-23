#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <windows.h> // Для Windows (UTF-8)

bool isPalindrome(const std::string& text) {
    // Очистка: только буквы и цифры, нижний регистр
    std::string cleaned;
    for (char c : text) {
        // Используем static_cast<unsigned char> для безопасной работы с isalnum
        if (std::isalnum(static_cast<unsigned char>(c))) {
            cleaned += std::tolower(static_cast<unsigned char>(c));
        }
    }

    // Сравнение с переворотом
    std::string reversed = cleaned;
    std::reverse(reversed.begin(), reversed.end());
    
    return cleaned == reversed;
}

int main() {
    // Включаем поддержку UTF-8 для корректного вывода кириллицы в консоли Windows
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    // Тесты
    std::string tests[] = {
        "А роза упала на лапу Азора",
        "Madam, I'm Adam",
        "Hello, World!",
        "12321",
        "racecar"
    };

    for (const auto& text : tests) {
        std::string result = isPalindrome(text) ? "палиндром" : "не палиндром";
        std::cout << text << " - " << result << "\n";
    }

    return 0;
}