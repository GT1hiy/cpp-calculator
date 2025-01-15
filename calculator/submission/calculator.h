// Ваше решение задачи о калькуляторе с классом.
#pragma once

#include <string>

using Number = double;

class Calculator {
public:
    void Set(Number n);
    Number GetNumber() const;
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);
    void Save();
    void Load();
    bool HasMem() const;
    std::string GetNumberRepr() const;
private:
    Number
        memory_ = 0,
        result_number_ = 0;
    bool
        has_remember = false;
};
