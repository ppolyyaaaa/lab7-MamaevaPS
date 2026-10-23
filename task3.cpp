#include <iostream>
#include <string>
#include <cctype>
#include <windows.h> // Для Windows (UTF-8)

std::string caesarCipher(const std::string& text, int shift) {
    std::string result = text;
    
    for (char& c : result) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            // Определяем базу: 'A' для заглавных, 'a' для строчных
            char base = std::isupper(static_cast<unsigned char>(c)) ? 'A' : 'a';
            
            // Применяем формулу: (код - база + сдвиг) % 26 + база
            // Приводим к int для безопасных вычислений, затем обратно к char
            int shifted = (static_cast<int>(c) - static_cast<int>(base) + shift) % 26;
            
            // В C++ остаток от де быть отрицательным.
            // Добавляем 26 и берем остаток снова, чтобы обработать отрицательный сдвиг.
            if (shifted < 0) {
                shifted += 26;
            }
            
            c = static_cast<char>(shifted + static_cast<int>(base));
        }
    }
    
    return result;
}

int main() {
    // Включаем поддержку UTF-8 для консоли Windows
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    std::string original = "Hello, World!";
    
    // Шифрование (сдвиг на 3)
    std::string encrypted = caesarCipher(original, 3);
    
    // Дешифрование (сдвиг на -3)
    std::string decrypted = caesarCipher(encrypted, -3);

    std::cout << "Оригинал:    " << original << "\n";
    std::cout << "Зашифровано: " << encrypted << "\n"; // Khoor, Zruog!
    std::cout << "Расшифровано: " << decrypted << "\n"; // Hello, World!

    return 0;
}