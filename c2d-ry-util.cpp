//
//  c2d-ry-util.cpp
//  Mine
//
//  Created by ray on 2019/5/17.
//

#include "c2d-ry-util.h"

RY_NAMESPACE_BEGIN

template<class K, class V>
bool Util::mapHasValue(std::map<K, V>& map, K key) {
    
    auto it = map.find(key);
    if (it != map.end()) {
        return true;
    };
    return false;
}


template<class K, class V>
V Util::mapGetValueSafe(std::map<K, V>& map, K key) {
    
    V p = nullptr;
    auto it = map.find(key);
    if (it != map.end()) {
        p = it->second;
    }
    return p;
}

template<class K, class V>
std::vector<K> Util::mapGetAllKeys(std::map<K, V>& map) {
    
    std::vector<K> list;
    for (auto vk : map) {
        list.push_back(vk->first);
    }
    return list;
}

template<class K, class V>
std::vector<V> Util::mapGetAllValues(std::map<K, V>& map) {
    
    std::vector<K> list;
    for (auto vk : map) {
        list.push_back(vk->second);
    }
    return list;
}

RY_NAMESPACE_END
