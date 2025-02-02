#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <QList>
#include "data_structures_global.h"
template <typename T>
class DATA_STRUCTURES_EXPORT PriorityQueue
{
public:
    PriorityQueue();
    bool isEmspty();
private:
    QList<T> heapq;
    int cursor = 0;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
    heapq = QList<T>{};
}

template<typename T>
bool PriorityQueue<T>::isEmspty()
{
    return cursor==0;

}

#endif // PRIORITYQUEUE_H
