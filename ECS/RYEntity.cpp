//
//  CCEntity.cpp
//  Vendor
//
//  Created by ray on 2019/5/16.
//

#include "RYEntity.hpp"

RY_NAMESPACE_BEGIN

void Entity::addComponent(Component *cmp, ComponentId identifier) {
    
    std::string name(identifier);
    RY_ASSERT(!RY_MAP_HAS_VALUE(_cmpMap, name), "same cmp exist");
    RY_ASSERT(cmp->_entity == nullptr, "cmp entity isn't null");
    _cmpMap[name] = cmp;
    cmp->_identifier = name;
    cmp->setEntity(this);
};

Component *Entity::component(ComponentId identifier) {
    
    auto res = _cmpMap.find(identifier);
    if (res != _cmpMap.end()) {
        auto value = res->second;
        RY_ASSERT(RY_REF_EXIST(value), "WTF")
        return value;
    }
    return nullptr;
};

RY_NAMESPACE_END
