#include "my_lib.h"

#include <gtest/gtest.h>
#include <iostream>

TEST(NormalTests, PositiveNumbers) {
    EXPECT_EQ(normal::f<int>(3, 4), 5);
    EXPECT_EQ(normal::f<int>(5, 12), 13);
}

TEST(NormalTests, NegativeNumbers) {
    EXPECT_EQ(normal::f<int>(-3, 4), 5);
    EXPECT_EQ(normal::f<int>(-3, -4), 5);
}

TEST(NormalTests, ZeroNumbers) {
    EXPECT_EQ(normal::f<int>(0, 0), 0);
    EXPECT_EQ(normal::f<int>(0, 7), 7);
    EXPECT_EQ(normal::f<int>(7, 0), 7);
}

TEST(NormalTests, IntegerResultTruncatesFraction) {
    EXPECT_EQ(normal::f<int>(2, 3), 3);
}

TEST(NormalTests, DoubleNumbers) {
    EXPECT_DOUBLE_EQ(normal::f<double>(1.5, 2.0), 2.5);
    EXPECT_DOUBLE_EQ(normal::f<double>(2.0, 2.0), std::sqrt(8.0));
}

TEST(NormalTests, FloatNumbers) {
    EXPECT_FLOAT_EQ(normal::f<float>(1.5f, 2.0f), 2.5f);
}

TEST(NormalTests, LongDoubleNumbers) {
    const long double result = normal::f<long double>(1.5L, 2.0L);
    EXPECT_LE(std::abs(result - 2.5L), 1e-15L);
}

TEST(NormalTests, SeparateResultType) {
    EXPECT_DOUBLE_EQ((normal::f<int, double>(2, 3)), std::sqrt(13.0));
}

TEST(NormalTests, LargeArguments) {
    EXPECT_EQ(normal::f<int>(30000, 40000), 50000);
    EXPECT_DOUBLE_EQ(normal::f<double>(3e200, 4e200), 5e200);
}

TEST(RandomizedTests, IntegerResultRange) {
    for (int i = 0; i < 100; ++i) {
        const int result = randomized::f<int>(3, 4);
        EXPECT_GE(result, 5);
        EXPECT_LE(result, 15);
    }
}

TEST(RandomizedTests, ZeroResultRange) {
    for (int i = 0; i < 100; ++i) {
        const int result = randomized::f<int>(0, 0);
        EXPECT_GE(result, 0);
        EXPECT_LE(result, 10);
    }
}

TEST(RandomizedTests, DoubleResultRange) {
    for (int i = 0; i < 100; ++i) {
        const double result = randomized::f<double>(1.5, 2.0);
        EXPECT_GE(result, 2.5);
        EXPECT_LE(result, 12.5);
        EXPECT_DOUBLE_EQ(result - 2.5, std::floor(result - 2.5));
    }
}

TEST(RandomizedTests, SeparateResultType) {
    const double expected = normal::f<int, double>(2, 3);
    for (int i = 0; i < 100; ++i) {
        const double result = randomized::f<int, double>(2, 3);
        EXPECT_GE(result, expected);
        EXPECT_LE(result, expected + 10.0);
    }
}

TEST(FailureTests, DISABLED_ExpectTest) {
    EXPECT_EQ(normal::f<int>(3, 4), 100);

    std::cout << "After EXPECT\n";
    EXPECT_EQ(normal::f<int>(5, 12), 100);
}

TEST(FailureTests, DISABLED_AssertTest) {
    ASSERT_EQ(normal::f<int>(3, 4), 100);

    std::cout << "After ASSERT\n";
    EXPECT_EQ(normal::f<int>(5, 12), 100);
}
