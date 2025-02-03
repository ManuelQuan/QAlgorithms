#ifndef MONOTONICQUEUE_H
#define MONOTONICQUEUE_H
#include <list>
#include <initializer_list>
#include "data_structures_global.h"

template <typename T>
class DATA_STRUCTURES_EXPORT MonostonicQueue
{
public:
    MonostonicQueue(std::initializer_list<T> srcList);
    void enqueue(T item);
    T dequeue();
    const T& front();
    const T& back();
    void showItems();

private:
    std::list<T> queue{};
};


template<typename T>
MonostonicQueue<T>::MonostonicQueue(std::initializer_list<T> srcList)
{
    for(T item : srcList)
    {
        enqueue(item);
    }

}

template<typename T>
void MonostonicQueue<T>::enqueue(T item)
{
    if( item > queue.front())
    {
        queue.clear();
        queue.push_back(item);
    }
    else
    {
        auto cursor = queue.rbegin();
        while(cursor != queue.rend() && ((*(cursor))<item))
        {
            cursor++;
        }
        queue.insert(cursor.base(),item);
    }
}

template<typename T>
T MonostonicQueue<T>::dequeue()
{
    T res;
    if(!queue.empty())
    {
        res = queue.front();
        queue.pop_front();
    }
    else
    {
        qDebug()<<"Empty Queue!";
    }

    return res;
}

template<typename T>
const T &MonostonicQueue<T>::front()
{
    return queue.front();
}

template<typename T>
const T &MonostonicQueue<T>::back()
{
    return queue.back();

}

template<typename T>
void MonostonicQueue<T>::showItems()
{
    for(auto begin = queue.begin();begin != queue.end();++begin)
    {
        qDebug() << (*(begin));
    }

}

#endif // MONOTONICQUEUE_H
