#ifndef INSERTIONSORTER_H
#define INSERTIONSORTER_H
#include "AbstractSorter.h"
#include "general_algorithms_global.h"
template <typename T>
class GENERAL_ALGORITHMS_EXPORT InsertionSorter : public AbstractSorter<T>
{
public:
    InsertionSorter(QList<T>);
    virtual void sort() override;
};

template<typename T>
InsertionSorter<T>::InsertionSorter(QList<T> _targets)
{
    this->targets = _targets;
}

template<typename T>
void InsertionSorter<T>::sort()
{
    int N = this->targets.size();
    for(int i{1}; i < N ; ++i)
    {
        T insertValue = this->targets.at(i);
        int insertIndex = i;
        while (insertIndex > 0 && this->less(insertIndex,insertIndex-1))
        {
            this->exchange(insertIndex,insertIndex-1);
            // this->targets[insertIndex] = this->targets[insertIndex-1];
            insertIndex--;
        }
        this->targets[insertIndex] = insertValue;
    }
}
#endif // INSERTIONSORTER_H
