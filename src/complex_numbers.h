#ifndef COMPLEXNUMBERS_COMPLEX_NUMBERS_H
#define COMPLEXNUMBERS_COMPLEX_NUMBERS_H
#include <exception>

struct ComplexNumber {
    double real = 0;
    double imaginary = 0;
};

class ComplexNumbersExceptions: public std::exception {
    ComplexNumbersExceptions(char* err);
} DivisionByZeroException;

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b);
void operator+=(ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b);
void operator-=(ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b);
void operator*=(ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator/(const ComplexNumber& a, const ComplexNumber& b);
void operator/=(ComplexNumber& a, const ComplexNumber& b);
std::ostream& operator<<(std::ostream& out, const ComplexNumber& a);

#endif
