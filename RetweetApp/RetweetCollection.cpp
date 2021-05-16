#include "RetweetCollection.hpp"
#include "Tweet.h"

RetweetCollection::RetweetCollection() : m_size(0)
{
}

bool RetweetCollection::isEmpty() const
{
    return (0 == size());
}

unsigned int RetweetCollection::size() const
{
    return m_size;
}

void RetweetCollection::add(const Tweet& tweet)
{
    m_size = 1;
}
