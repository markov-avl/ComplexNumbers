#include "gtest/gtest.h"
#include "complex_numbers.h"

TEST(operatorPlus, expectedSum) {
    ComplexNumber a, b, sum;
    a.real = -0.3;
    a.imaginary = 8;
    b.real = 0;
    b.imaginary = 3.9;
    sum = a + b;
    EXPECT_DOUBLE_EQ(sum.real, -0.3);
    EXPECT_DOUBLE_EQ(sum.imaginary, 11.9);
    a.real = 53.09;
    a.imaginary = -32.1;
    sum += a;
    EXPECT_DOUBLE_EQ(sum.real, 52.79);
    EXPECT_DOUBLE_EQ(sum.imaginary, -20.2);
}

TEST(operatorMinus, expectedDifference) {
    ComplexNumber a, b, sub;
    a.real = 92.87;
    a.imaginary = 11;
    b.real = -0.31;
    b.imaginary = 1.11;
    sub = a - b;
    EXPECT_DOUBLE_EQ(sub.real, 93.18);
    EXPECT_DOUBLE_EQ(sub.imaginary, 9.89);
    a.real = 780;
    a.imaginary = -0.981;
    sub -= a;
    EXPECT_DOUBLE_EQ(sub.real, -686.82);
    EXPECT_DOUBLE_EQ(sub.imaginary, 10.871);
}

TEST(operatorMultiplication, expectedProduct) {
    ComplexNumber a, b, product;
    a.real = 0;
    a.imaginary = 43.09;
    b.real = -7.83;
    b.imaginary = 0;
    product = a * b;
    EXPECT_DOUBLE_EQ(product.real, 0);
    EXPECT_DOUBLE_EQ(product.imaginary, -337.3947);
    a.real = 91;
    a.imaginary = -0.5;
    product *= a;
    EXPECT_DOUBLE_EQ(product.real, -168.69735);
    EXPECT_DOUBLE_EQ(product.imaginary, -30702.9177);
}

TEST(operatorDivision, expectedQuotient) {
    ComplexNumber a, b, quotient;
    a.real = -2;
    a.imaginary = 1;
    b.real = 1;
    b.imaginary = -1;
    quotient = a / b;
    EXPECT_DOUBLE_EQ(quotient.real, -1.5);
    EXPECT_DOUBLE_EQ(quotient.imaginary, -0.5);
    a.real = 4;
    a.imaginary = 3;
    quotient /= a;
    EXPECT_DOUBLE_EQ(quotient.real, -0.3);
    EXPECT_DOUBLE_EQ(quotient.imaginary, 0.1);
}

TEST(operatorDivision, expectedDivisionByZeroException) {
    ComplexNumber a, b;
    a.real = -10;
    a.imaginary = 20;
    b.real = 0;
    b.imaginary = 0;
    EXPECT_THROW(a / b, ComplexNumberException);
}

TEST(operatorOut, expectedOutput) {
    ComplexNumber a;

    a.real = 0.32;
    a.imaginary = 98;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "0.32+98i");

    a.real = -0.32;
    a.imaginary = -98;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-0.32-98i");

    a.real = 0;
    a.imaginary = 16.3;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "16.3i");

    a.real = 0;
    a.imaginary = -16.3;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-16.3i");

    a.real = 52.9;
    a.imaginary = 0;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "52.9");

    a.real = -52.9;
    a.imaginary = 0;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-52.9");

    a.real = 0;
    a.imaginary = 0;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "0");

    a.real = 1;
    a.imaginary = 1;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1+i");

    a.real = -1;
    a.imaginary = -1;
    testing::internal::CaptureStdout();
    std::cout << a;
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-1-i");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
