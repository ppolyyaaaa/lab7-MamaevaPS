#include <iostream>
#include <string>
#include <regex>
#include <windows.h> // Для Windows (UTF-8)

bool validateEmail(const std::string& email) {
    // Регулярное выражение для проверки email
    std::regex pattern(R"([\w.+-]+@[\w-]+\.[\w.-]+$)");
    return std::regex_match(email, pattern);
}

bool validatePhone(const std::string& phone) {
    // Регулярное выражение для проверки российского телефона
    std::regex pattern(R"(\+7?\s?\(?\d{3}\)?[\s-]?\d{3}[\s-]?\d{2}[\s-]?\d{2}$)");
    return std::regex_match(phone, pattern);
}

bool validateUrl(const std::string& url) {
    // Регулярное выражение для проверки URL
    std::regex pattern(R"(https?://[\w.-]+\.[a-z]{2,}(/[\w./-]*)?$)");
    return std::regex_match(url, pattern);
}

int main() {
    // Включаем поддержку UTF-8 для корректного отображения кириллицы в консоли Windows
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    std::cout << std::boolalpha;

    // Тесты
    std::cout << "Email valid:   " << validateEmail("ivan@example.com") << "\n"; // true
    std::cout << "Email invalid: " << validateEmail("invalid@") << "\n";         // false
    std::cout << "Phone valid:   " << validatePhone("+7 (999) 123-45-67") << "\n"; // true
    std::cout << "URL valid:     " << validateUrl("https://example.com") << "\n";  // true

    return 0;
}