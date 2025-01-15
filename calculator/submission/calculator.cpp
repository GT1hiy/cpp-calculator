// Ваше решение задачи о калькуляторе с классом.
#include "calculator.h"

#include <cassert>
#include <cmath>

void Calculator::Set(Number n) {
    result_number_ = n;
};

Number Calculator::GetNumber() const {
    return result_number_;
};

void Calculator::Add(Number n) {
    result_number_ += n;
};

void Calculator::Sub(Number n) {
    result_number_ -= n;
};

void Calculator::Div(Number n) {
    result_number_ /= n;
};

void Calculator::Mul(Number n) {
    result_number_ *= n;
};

void Calculator::Pow(Number n) {
    Number basis = result_number_;
    result_number_ = pow(basis,n);
};

void Calculator::Save() {
    memory_ = result_number_;
    has_remember = true;
};

void Calculator::Load() {
    result_number_ = memory_;
};

bool  Calculator::HasMem() const {
    return has_remember;
};

std::string Calculator::GetNumberRepr() const {
    return std::to_string (result_number_);
}




