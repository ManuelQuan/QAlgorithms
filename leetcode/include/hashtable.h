#pragma once

#include "leetcode_gobal.h"
#include <QHash>
class LEETCODE_EXPORT HashTable
{
public:
    template <typename T>
    static QList<T> twoSum(QList<T>& nums,int target);
};

template<typename T>
QList<T> HashTable::twoSum(QList<T> &nums, int target)
{
    QList<T> res;
    QHash<T,T> hashtable;
    for(int i {0};i<nums.size();++i)
    {
        auto it = hashtable.find(target - nums[i]);
        if(it != hashtable.end())
        {
            res<< it.value() << i;
            return res;
        }
        hashtable[nums[i]] = i;
    }
    return res;

}
