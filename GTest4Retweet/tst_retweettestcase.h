#ifndef TST_RETWEETTESTCASE_H
#define TST_RETWEETTESTCASE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(RetweetTestSuite, RetweetTestCase)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_RETWEETTESTCASE_H
