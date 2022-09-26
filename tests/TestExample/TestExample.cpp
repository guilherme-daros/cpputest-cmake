#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup){};

TEST(FirstTestGroup, FirstTest)
{
    CHECK(true);
}

TEST(FirstTestGroup, SecondTest)
{
    STRCMP_EQUAL("hello", "hello");
    LONGS_EQUAL(1, 1);
    CHECK(true);
}