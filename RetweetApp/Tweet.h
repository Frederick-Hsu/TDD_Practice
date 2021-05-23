#ifndef TWEET_H
#define TWEET_H

    #include <string>

    class Tweet;

    class Tweet
    {
    public:
        Tweet();
        Tweet(const std::string& message, const std::string& username);
    };

#endif  /* TWEET_H */
