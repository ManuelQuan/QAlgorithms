#ifndef BUCKETSORTER_H
#define BUCKETSORTER_H
#include <algorithm>
#include "AbstractSorter.hpp"
#include "general_algorithms_global.h"
template <typename T>
class GENERAL_ALGORITHMS_EXPORT BucketSorter : public AbstractSorter<T>
{
public:
    BucketSorter(QList<T>);
    virtual void sort() override;
};

template<typename T>
BucketSorter<T>::BucketSorter(QList<T> _targets)
{
    this->targets = _targets;
}

template<typename T>
void BucketSorter<T>::sort()
{
    int N = this->targets.size();
    // unittest scope is 0 ~ 100;
    QList<QList<T>> buckets(10);
    for(int i {0}; i < N ; ++i)
    {
        int index = this->targets[i] / 10;
        if(index < 0 ) index *= -1;
        buckets[index].push_back(this->targets[i]);
    }

    for(int i{0}; i<10; ++i)
    {
        std::sort(buckets[i].begin(),buckets[i].end());
    }

    int index = 0;
    for(int i{0};i<10;++i)
    {
        for(int j{0};j<buckets[i].size();++j)
        {
            this->targets[index++] = buckets[i][j];

        }
    }
}
#endif // BUCKETSORTER_H
