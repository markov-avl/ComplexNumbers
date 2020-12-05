#include <exception>

#ifndef COMPLEXNUMBERS_COMPLEX_NUMBERS_H
#define COMPLEXNUMBERS_COMPLEX_NUMBERS_H

struct ComplexNumber {
    double real = 0;
    double imaginary = 0;
};

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator+=(const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator-=(const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator*=(const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator/(const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator/=(const ComplexNumber& a, const ComplexNumber& b);
std::ostream& operator<<(std::ostream& out, const ComplexNumber& a);

class ComplexNumbersExceptions: public std::exception {
    virtual const char* what() const noexcept override;
} DivisionByZeroException;

#endif
