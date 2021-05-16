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

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated)
{
    ASSERT_THAT(collection.size(), Eq(0u));
}

TEST_F(ARetweetCollection, IsNoLongerEmptyAfterTweetAdded)
{
    collection.add(Tweet());
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeOfOneAfterTweetAdded)
{
    collection.add(Tweet());
    ASSERT_THAT(collection.size(), Eq(1u));
}
