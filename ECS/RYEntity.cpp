//
//  CCEntity.cpp
//  Vendor
//
//  Created by ray on 2019/5/16.
//

#include "RYEntity.hpp"

RY_NAMESPACE_BEGIN

void Entity::addComponent(Component *cmp, ComponentId identifier) {
    
    RY_ASSERT(!RY_MAP_HAS_VALUE(_cmpMap, identifier), "same cmp exist");
    RY_ASSERT(cmp->_entity == nullptr, "cmp entity isn't null");
    
    _cmpMap[identifier] = cmp;
    cmp->_identifier = identifier;
    cmp->setEntity(this);
};

Component *Entity::component(ComponentId identifier) {
    auto cmp = RY_UTIL::mapGetValueSafe(_cmpMap, identifier);
    return cmp;
};

RY_NAMESPACE_END
