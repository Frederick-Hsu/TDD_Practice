#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../RetweetApp/RetweetCollection.hpp"
#include "../RetweetApp/Tweet.h"

using namespace ::testing;

class ARetweetCollection : public ::testing::Test
{
public:
    RetweetCollection collection;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated)
{
    bool result = collection.isEmpty();
    ASSERT_TRUE(result);
}

TEST_F(ARetweetCollection, IsNoLongerEmptyAfterTweetAdded)
{
    collection.add(Tweet());
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated)
{
    ASSERT_THAT(collection.size(), Eq(0u));
}

TEST_F(ARetweetCollection, HasSizeOfOneAfterTweetAdded)
{
    collection.add(Tweet());
    ASSERT_THAT(collection.size(), Eq(1u));
}

MATCHER_P(HasSize, expected, "")
{
    return (arg.size() == expected) && (arg.isEmpty() == (0 == expected));
}

TEST_F(ARetweetCollection, DecresesSizeAfterRemovingTweet)
{
    collection.add(Tweet());
    collection.remove(Tweet());
    ASSERT_THAT(collection, HasSize(0u));
}

TEST_F(ARetweetCollection, IsEmptyWhenItsSizeIsZero)
{
    ASSERT_THAT(collection.size(), Eq(0u));
    ASSERT_TRUE(collection.isEmpty());
}
