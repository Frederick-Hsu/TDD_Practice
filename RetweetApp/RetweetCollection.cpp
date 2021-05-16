#include "RetweetCollection.hpp"
#include "Tweet.h"

#include <algorithm>
#include <functional>

RetweetCollection::RetweetCollection() : m_size(0)
{
}

bool RetweetCollection::isEmpty() const
{
    return (m_size == 0);
}

unsigned int RetweetCollection::size() const
{
    return m_size;
}

void RetweetCollection::add(const Tweet&)
{
    m_size++;
}

void RetweetCollection::remove(const Tweet&)
{
    m_size--;
}
