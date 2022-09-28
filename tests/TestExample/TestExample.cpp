#include "CppUTest/TestHarness.h"

TEST_GROUP(TestExample){};

TEST(TestExample, FirstTest)
{
    CHECK(true);
}

TEST(TestExample, SecondTest)
{
    STRCMP_EQUAL("hello", "hello");
    LONGS_EQUAL(1, 1);
    CHECK(true);
}