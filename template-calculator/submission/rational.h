#pragma once

#include <numeric>
#include <cstdlib>
#include <compare>
#include <iostream>

// Реализуйте класс Rational.

class Rational {
public:
    Rational(int numerator, int denominator)
        : numerator_(numerator)
        , denominator_(denominator) {
        if (denominator_ == 0) {
            std::abort();
        }
        // Приводим дробь к правильному формату.
        Reduction();
    }

    Rational() = default;
    Rational(int numerator) : numerator_(numerator), denominator_{1} {}
    Rational(const Rational &r) : numerator_{r.numerator_}, denominator_{r.denominator_} {}

    bool operator==(const Rational& r) const = default;

    Rational& operator=(const Rational &r) {
        numerator_ = r.numerator_;
        denominator_ = r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator+=(const Rational& r) {
        numerator_ = numerator_ * r.denominator_
                     + r.numerator_ * denominator_;
        denominator_ *= r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator-=(const Rational& r) {
        numerator_ = numerator_ * r.denominator_
                     - r.numerator_ * denominator_;
        denominator_ *= r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator*=(const Rational& r) {
        numerator_ *= r.numerator_;
        denominator_ *= r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator/=(const Rational& r) {
        numerator_ *= r.denominator_;
        denominator_ *= r.numerator_;
        Reduction();
        return *this;
    }

    Rational operator+() const {
        return *this;
    }

    Rational operator-() const {
        if ((numerator_ < 0) && (denominator_ < 0)) {
            return Rational{numerator_, -denominator_};
        }
        return Rational{-numerator_, denominator_};
    }

    Rational operator+(const Rational& other) const {
        return Rational(numerator_ * other.denominator_
                            + denominator_ * other.numerator_, denominator_
                            * other.denominator_);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numerator_ * other.denominator_
                            - denominator_ * other.numerator_, denominator_
                            * other.denominator_);
    }

    Rational operator*(const Rational& other) const {
        return Rational(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Rational operator/(const Rational& other) const {
        return Rational(numerator_ * other.denominator_, other.numerator_ * denominator_);
    }

    auto operator<=>(const Rational& other) const {
        return (numerator_ * other.denominator_) <=> (other.numerator_ * denominator_);
    }

    Rational Inv() const {
        return Rational{denominator_, numerator_};
    }

    int GetNumerator() const {
        return numerator_;
    }

    int GetDenominator() const {
        return denominator_;
    }

private:
    // Метод для приведения дроби к корректной форме.
    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }

private:
    int numerator_ = 0;
    int denominator_ = 1;
};

inline std::ostream& operator<<(std::ostream& os, const Rational &r) {
    if (r.GetDenominator() == 1) {
        os << r.GetNumerator();
        return os;
    }
    os << r.GetNumerator() << " / " << r.GetDenominator();
    return os;
}

inline std::istream& operator>>(std::istream& is, Rational &r) {
    int numerator;
    int denominator;
    char slash;
    if (!(is >> numerator)) {
        return is;
    }

    if (!(is >> std::ws >> slash) || !(slash == '/')) {
        r = Rational(numerator);
        return is;
    }

    if (!(is >> denominator)) {
        r = Rational{numerator};
        return is;
    }

    if (denominator == 0) {
        is.setstate(std::ios_base::failbit);
        return is;
    }

    r = Rational(numerator, denominator);
    return is;
}
