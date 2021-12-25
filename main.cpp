#include "gtest/gtest.h"
#include "RationalNumber.h"

class Tests : public ::testing::Test {
protected:
    void SetUp() {
        r2 = { 5, 1, 0 };
        r3 = { 3, 8, 0 };
        r4 = { -1, 3, 0 };
        r5 = { 5, 8, 0 };
        r6 = { 7, 4, 0 };
        r7 = { 1, 2, 0 };
        r8 = { -1, 3, 0 };
        r9 = { 0, 8, 0 };
        r10 = { 4, 8, 0 };
        r11 = { 8, 8, 0 };
        r12 = { 12, 8, 0};
        r13 = { -4, 8, 0 };
    }
    void TearDown() {
    }
    RationalNumber<int> r1;
    RationalNumber<int> r2;
    RationalNumber<int> r3;
    RationalNumber<int> r4;
    RationalNumber<int> r5;
    RationalNumber<int> r6;
    RationalNumber<int> r7;
    RationalNumber<int> r8;
    RationalNumber<int> r9;
    RationalNumber<int> r10;
    RationalNumber<int> r11;
    RationalNumber<int> r12;
    RationalNumber<int> r13;
};


TEST_F(Tests, sum) {
    ASSERT_EQ(r3 + r5, RationalNumber<int>(1, 1, 0));
    ASSERT_EQ(r3 + r6, RationalNumber<int>(1, 8, 2));
    ASSERT_EQ(r7 + r4, RationalNumber<int>(1, 6, 0));
}


TEST_F(Tests, mult) {
    ASSERT_EQ(r3 * r5, RationalNumber<int>(15, 64, 0));
    ASSERT_EQ(r3 * r6, RationalNumber<int>(21, 32, 0));
    ASSERT_EQ(r7 * r4, RationalNumber<int>(-1, 6, 0));
    ASSERT_EQ(r7 * r9, RationalNumber<int>(0, 1, 0));
}

TEST_F(Tests, subst) {
    ASSERT_EQ(r5 - r3, RationalNumber<int>(1, 4, 0));
    ASSERT_EQ(r6 - r3, RationalNumber<int>(3, 8, 1));
    ASSERT_EQ(r7 - r8, RationalNumber<int>(5, 6, 0));
}
TEST_F(Tests, div) {
    ASSERT_EQ(r3 / r5, RationalNumber<int>(3, 5, 0));
    ASSERT_EQ(r3 / r6, RationalNumber<int>(3, 14, 0));
    ASSERT_EQ(r7 / r4, RationalNumber<int>(-1, 2, -1));
}
TEST_F(Tests, simplif) {
    +r3;
    +r10;
    +r11;
    +r12;
    +r13;
    +r9;
    ASSERT_EQ(r3, RationalNumber<int>(3, 8, 0));
    ASSERT_EQ(r10, RationalNumber<int>(1, 2, 0));
    ASSERT_EQ(r11, RationalNumber<int>(1, 1, 0));
    ASSERT_EQ(r12, RationalNumber<int>(3, 2, 0));
    ASSERT_EQ(r13, RationalNumber<int>(-1, 2, 0));
    ASSERT_EQ(r9, RationalNumber<int>(0, 1, 0));
}