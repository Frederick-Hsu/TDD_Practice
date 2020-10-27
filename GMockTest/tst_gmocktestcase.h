#ifndef TST_GMOCKTESTCASE_H
#define TST_GMOCKTESTCASE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(GMockTestSuite, GMockTestCase)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_GMOCKTESTCASE_H
