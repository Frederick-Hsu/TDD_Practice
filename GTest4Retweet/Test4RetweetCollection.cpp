#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../RetweetApp/RetweetCollection.hpp"
#include "../RetweetApp/Tweet.h"

class ARetweetCollectionWithOneTweet : public ::testing::Test
{
public:
    RetweetCollection collection;
    Tweet* ptweet;
public:
    void SetUp() override
    {
        ptweet = new Tweet("msg", "@user");
        collection.add(*ptweet);
    }

    void TearDown() override
    {
        delete ptweet;
        ptweet = nullptr;
    }
};

TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmpty)
{
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollectionWithOneTweet, HasSizeOfOne)
{
    ASSERT_THAT(collection.size(), ::testing::Eq(1u));
}
