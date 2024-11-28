#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H
#include "../general_algorithms_global.h"
#include "AbstractSorter.hpp"

template <typename T>
class GENERAL_ALGORITHMS_EXPORT BubbleSorter: public AbstractSorter<T>
{
public:
    BubbleSorter(QList<T>);
    virtual void sort() override;
};

template<typename T>
BubbleSorter<T>::BubbleSorter(QList<T> _targets)
{
    this->targets = _targets;
}

template <typename T>
void BubbleSorter<T>::sort()
{
    int N = this->targets.size();
    for(int i{N-1};i>=0;--i)
    {
        bool sorted = true;
        for(int j{0};j<i;++j)
        {
            if(this->less(j+1,j))
            {
                sorted = false;
                this->exchange(j,j+1);
            }
        }
        if(sorted) break;
    }
}


#endif // BUBBLESORTER_H
