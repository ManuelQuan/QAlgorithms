#ifndef ABSTRACTSORTER_H
#define ABSTRACTSORTER_H
#include "../general_algorithms_global.h"
#include <QList>

template <typename T>
class GENERAL_ALGORITHMS_EXPORT AbstractSorter {
public:
    virtual void sort() = 0;
    virtual QList<T> getTargets() const = 0;
protected:
    bool less(int i,int j);
    void exchange(int i,int j);
    QList<T> targets;
};

template<typename T>
bool AbstractSorter<T>::less(int i, int j)
{
    return targets.at(i) < targets.at(j);
}

template<typename T>
void AbstractSorter<T>::exchange(int i, int j)
{
    targets.swapItemsAt(i,j);
}

#endif // ABSTRACTSORTER_H
