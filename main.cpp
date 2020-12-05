#include <iostream>
#include "complex_numbers.h"

int main() {
    ComplexNumber a, b, c;
    a.real = -0.3;
    a.imaginary = 8;
    b.real = 0;
    b.imaginary = 3.9;
    c = a + b;
    a.real = 53.09;
    a.imaginary = -32.1;
    c += a;
    std::cout << c;
    throw DivisionByZeroException;
}
