#include "gtest/gtest.h"
#include "complex_numbers.h"

TEST(operatorPlus, expectedEquality) {
    ComplexNumber a, b, sum;
    a.real = -0.3;
    a.imaginary = 8;
    b.real = 0;
    b.imaginary = 3.9;
    sum = a + b;
    EXPECT_EQ(sum.real, (double)-0.3);
    EXPECT_EQ(sum.imaginary, (double)11.9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}