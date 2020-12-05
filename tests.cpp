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
    EXPECT_EQ(sub.real, (double)93.18);
    EXPECT_EQ(sub.imaginary, (double)9.89);
}

TEST(operatorMultiplication, expectedProductEquality) {
    ComplexNumber a, b, product;
    a.real = 0;
    a.imaginary = 43.09;
    b.real = -7.83;
    b.imaginary = 0;
    product = a * b;
    EXPECT_EQ(product.real, (double)0);
    EXPECT_EQ(product.imaginary, (double)-337.395);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}