#pragma once

#include <string>
#include <optional>
#include <cmath>
#include "rational.h"
#include "pow.h"

using Error = std::string;

template<typename T>
class Calculator {
public:
    void Set(T n) {
        current_num_ = n;
    }

    T GetNumber() const {
        return current_num_;
    }

    std::optional<Error> Add(T n) {
        current_num_ += n;
        return std::nullopt;
    }

    std::optional<Error> Sub(T n) {
        current_num_ -= n;
        return std::nullopt;
    }

    std::optional<Error> Div(T n);

    std::optional<Error> Mul(T n) {
        current_num_ *= n;
        return std::nullopt;
    }

    std::optional<Error> Pow(T n);

    void Save() {
        buffer_opt_ = current_num_;
    }

    void Load() {
        if (buffer_opt_.has_value()) {
            current_num_ = buffer_opt_.value();
        }
    }

    std::optional<T> GetHasMem() const {
        return buffer_opt_;
    }

    std::string GetNumberRepr() const {
        return std::to_string(current_num_);
    }

private:
    T current_num_;
    std::optional<T> buffer_opt_ = std::nullopt;
    bool buffer_is_filled_ = false;
};

template<typename T>
inline std::optional<Error> Calculator<T>::Div(T n) {
    if (n == 0) {
        return "Division by zero";
    }
    current_num_ /= n;
    return std::nullopt;
}

template<>
inline std::optional<Error> Calculator<float>::Div(float n) {
    current_num_ /= n;
    return std::nullopt;
}

template<>
inline std::optional<Error> Calculator<double>::Div(double n) {
    current_num_ /= n;
    return std::nullopt;
}

template<typename T>
inline std::optional<Error> Calculator<T>::Pow(T n) {
    if ((current_num_ == 0) && (n == 0)) {
        return "Zero power to zero";
    }
    if (n < 0) {
        return "Integer negative power";
    }
    current_num_ = ::IntegerPow(current_num_, n);
    return std::nullopt;
}

template<>
inline std::optional<Error> Calculator<float>::Pow(float n) {
    if ((current_num_ == 0) && (n == 0)) {
        return "Zero power to zero";
    }
    current_num_ = std::pow(current_num_, n);
    return std::nullopt;
}

template<>
inline std::optional<Error> Calculator<double>::Pow(double n) {
    if ((current_num_ == 0) && (n == 0)) {
        return "Zero power to zero";
    }
    current_num_ = std::pow(current_num_, n);
    return std::nullopt;
}

template<>
inline std::optional<Error> Calculator<Rational>::Pow(Rational n) {
    if ((n.GetNumerator() == 0) && (current_num_.GetNumerator() == 0))
        return "Zero power to zero";

    if (n.GetDenominator() != 1) {
        return "Fractional power is not supported";
    }
    current_num_ = ::Pow(current_num_, n);
    return std::nullopt;
}
