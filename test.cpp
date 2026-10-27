#include <gtest/gtest.h>

#define main hidden_main
#include "main.cpp"
#undef main

TEST(CountpositiveTest, CountsCorrectly) {
    double a[] = {-1.0, 2.0, 3.5, -4.0};
    EXPECT_EQ(Countpositive(a, 4), 2);
}

TEST(LastzeroTest, FindsLastZeroIndex) {
    double a[] = {0.0, 1.0, 0.0, 3.0};
    EXPECT_EQ(Lastzero(a, 4), 2);
}

TEST(SumTest, CalculatesSumAfterLastZero) {
    double a[] = {0.0, 1.0, 0.0, 3.0, 2.0};
    EXPECT_EQ(SumAfterLzero(a, 5, 2), 5);
}