#ifndef RETWEET_COLLECTION_HPP
#define RETWEET_COLLECTION_HPP

    #include <vector>

    class RetweetCollection;
    class Tweet;

    class RetweetCollection
    {
    public:
        RetweetCollection();
        bool isEmpty() const;
        unsigned int size() const;
        void add(const Tweet& tweet);
        void remove(const Tweet& tweet);
    private:
        unsigned int m_size;
    };


#endif  /* RETWEET_COLLECTION_HPP */
