//
// Created by Proprio on 2020-09-13.
//

#ifndef EX1_MAPUTIL_H
#define EX1_MAPUTIL_H


#include <map>

class MapUtil {
public:
    template< typename K, typename V>
    static K getMapKeyByValue(V value, std::map<K, V> dict);
};

template<typename K, typename V>
K MapUtil::getMapKeyByValue(V value, std::map<K, V> dict) {
    for (auto & it : dict)
        if (it.second == value)
            return it.first;
}


#endif //EX1_MAPUTIL_H
