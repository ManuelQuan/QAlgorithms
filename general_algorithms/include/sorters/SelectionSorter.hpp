#ifndef SELECTIONSORTER_H
#define SELECTIONSORTER_H
#include "../general_algorithms_global.h"
#include "AbstractSorter.h"

template <typename T>
class GENERAL_ALGORITHMS_EXPORT SelectionSorter: AbstractSorter<T>
{
public:
    SelectionSorter(QList<T>);
    virtual void sort() override;
    virtual QList<T> getTargets() const override;
};

template<typename T>
SelectionSorter<T>::SelectionSorter(QList<T> _targets)
{
    this->targets = _targets;
}

template <typename T>
void SelectionSorter<T>::sort()
{
    int N = this->targets.size();
    for(int outer{0};outer < N;++outer)
    {
        T min = outer;
        for(int inner{outer + 1};inner < N;++inner)
        {
            if(this->less(inner,min))
            {
                min = inner;
            }
        }
        this->exchange(outer,min);
    }
}

template<typename T>
QList<T> SelectionSorter<T>::getTargets() const
{
    return this->targets;

}


#endif // SELECTIONSORTER_H
