#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
#include <string>
#include <numeric>
#include <windows.h> // Для Windows (UTF-8)

int main() {
    // Включаем поддержку UTF-8 для корректного отображения кириллицы в консоли Windows
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    // Вектор кортежей: имя, возраст, средний балл
    std::vector<std::tuple<std::string, int, double>> students = {
        {"Иван", 25, 4.5},
        {"Мария", 22, 4.85},
        {"Пётр", 30, 4.2},
        {"Анна", 20, 4.95}
    };

    // Заголовок
    std::cout << std::left << std::setw(15) << "Имя"
              << std::right << std::setw(8) << "Возраст"
              << std::setw(10) << "Балл" << "\n";
    
    // Разделитель (подобрана длина под общую ширину колонок)
    std::cout << std::string(33, '-') << "\n";

    // Данные
    // Устанавливаем фиксированную точность (2 знака после запятой)
    std::cout << std::fixed << std::setprecision(2);
    
    double totalGpa = 0.0;

    for (const auto& [name, age, gpa] : students) {
        std::cout << std::left  << std::setw(15) << name
                  << std::right << std::setw(8)  << age
                  << std::setw(10) << gpa << "\n";
        totalGpa += gpa;
    }

    // Итог
    std::cout << std::string(33, '-') << "\n";
    
    double avgGpa = totalGpa / students.size();
    
    std::cout << std::left  << std::setw(23) << "Средний балл"
              << std::right << std::setw(10) << avgGpa << "\n";

    return 0;
}
