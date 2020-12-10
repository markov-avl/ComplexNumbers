#include <iostream>
#include "complex_numbers.h"


ComplexNumberException::ComplexNumberException(std::string error) {
    this->error = std::move(error);
}

const char* ComplexNumberException::what() const noexcept {
    return this->error.c_str();
}


ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
    ComplexNumber sum;
    sum.real = a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;
    return sum;
}

void operator+=(ComplexNumber& a, const ComplexNumber& b) {
    a = a + b;
}

ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b) {
    ComplexNumber sub;
    sub.real = a.real - b.real;
    sub.imaginary = a.imaginary - b.imaginary;
    return sub;
}

void operator-=(ComplexNumber& a, const ComplexNumber& b) {
    a = a - b;
}

ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b) {
    ComplexNumber product;
    product.real = a.real * b.real - a.imaginary * b.imaginary;
    product.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return product;
}

void operator*=(ComplexNumber& a, const ComplexNumber& b) {
    a = a * b;
}

ComplexNumber operator/(const ComplexNumber& a, const ComplexNumber& b) {
    if (b.real == 0 && b.imaginary == 0) {
        throw ComplexNumberException("A complex number can't be divided by zero");
    } else {
        ComplexNumber quotient;
        double denominator = b.real * b.real + b.imaginary * b.imaginary;
        quotient.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
        quotient.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
        return quotient;
    }
}

void operator/=(ComplexNumber& a, const ComplexNumber& b) {
    a = a / b;
}

std::ostream& operator<<(std::ostream& out, const ComplexNumber& a) {
    if (a.real == 0 && a.imaginary == 0) {
        out << 0;
    } else {
        if (a.real != 0) {
            out << a.real;
            if (a.imaginary > 0) {
                out << '+';
            }
        }
        if (a.imaginary != 0) {
            if (a.imaginary == 1) {
                out << 'i';
            } else if (a.imaginary == -1) {
                out << "-i";
            } else {
                out << a.imaginary << 'i';
            }
        }
    }
    return out;
}
