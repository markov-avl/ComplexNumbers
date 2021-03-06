#ifndef COMPLEXNUMBERS_COMPLEX_NUMBERS_H
#define COMPLEXNUMBERS_COMPLEX_NUMBERS_H
#include <exception>
#include <utility>

struct ComplexNumber {
    double real = 0;
    double imaginary = 0;
};

class ComplexNumberException: public std::exception {
private:
    std::string error;
public:
    explicit ComplexNumberException(std::string error);
    const char* what() const noexcept override;
};

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
