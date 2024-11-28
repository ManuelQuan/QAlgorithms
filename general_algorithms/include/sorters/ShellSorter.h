#ifndef SHELLSORTER_H
#define SHELLSORTER_H
#include "../general_algorithms_global.h"
#include "AbstractSorter.hpp"

template <typename T>
class GENERAL_ALGORITHMS_EXPORT ShellSorter: public AbstractSorter<T>
{
public:
    ShellSorter(QList<T>);
    virtual void sort() override;

};

template<typename T>
ShellSorter<T>::ShellSorter(QList<T> _targets)
{
    this->targets = _targets;
}

template <typename T>
void ShellSorter<T>::sort()
{
    int N = this->targets.size();
    int h = 1;
    while(h < (N/3))
    {
        h = h*3+1;
    }
    while(h >= 1)
    {
        for(int i{h};i<N;++i)
        {
            for(int j{i};j>=h && this->less(j,j-h);j-=h)
            {
                this->exchange(j,j-h);
            }
        }
        h /= 3;
    }


}
#endif // SHELLSORTER_H
