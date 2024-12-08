#include "calculator.h"

using Number = double;

bool ReadNumber(Number& x) {
    std::cin >> x;
    if (std::cin.fail()) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false; // Возврат false при ошибке
    }
    return true; // Успешное чтение
}

void RunCalculatorCycle() {
    Number save = 0; // Переменная для хранения значений
    Number x = 0;

    using namespace std::literals;

    std::string token;
    while (std::cin >> token) {
        double right;

        if (token == "+"s) {
            if (!ReadNumber(right))
                break;
            x += right;
        }
        else if (token == "-"s) {
            if (!ReadNumber(right))
                break;
            x -= right;
        }
        else if (token == "*"s) {
            if (!ReadNumber(right))
                break;
            x *= right;
        }
        else if (token == "/"s) {
            if (!ReadNumber(right))
                break;
            x /= right;
        }
        else if (token == "s"s) {  // Сохранить в память
            save = x;
        }
        else if (token == "l"s) {  // Загрузить из памяти
            if (save == 0()) {
                std::cerr << "Error: Memory is empty" << std::endl;
            } else {
                x = save;  // Загружаем последнее сохраненное значение
            }
        }
        else if (token == "**"s) {
            if (!ReadNumber(right))
                break;
            x = std::pow(x, right);
        }
        else if (token == "="s) {
            std::cout << x << std::endl;
        }
        else if (token == "c"s) {
            x = 0;
        }
        else if (token == ":"s) {
            if (!ReadNumber(right))
                break;
            x = right;
        }
        else if (token == "q"s) {
            break;
        }
        else if (!ReadNumber(x)) {
        }
        else {
            std::cerr << "Error: Unknown token "s << token << std::endl;
            break;
        }
    }
}

