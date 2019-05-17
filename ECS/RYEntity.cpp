//
//  CCRYEntity.cpp
//  Vendor
//
//  Created by ray on 2019/5/16.
//

#include "RYEntity.hpp"

RY_NAMESPACE_BEGIN

void RYEntity::addComponent(RYComponent *cmp, const RYComponentIdentifier& identifier) {
    
    auto name = identifier.getName();
    RY_ASSERT(!RY_MAP_HAS_VALUE(_cmpMap, name), "same cmp exist");
    RY_ASSERT(cmp->_entity == nullptr, "cmp entity isn't null");
    _cmpMap[name] = cmp;
    cmp->setEntity(this);
};

RYComponent *RYEntity::component(const RYComponentIdentifier& identifier) {
    
    auto res = _cmpMap.find(identifier.getName());
    if (res != _cmpMap.end()) {
        auto value = res->second;
        RY_ASSERT(RY_REF_EXIST(value), "WTF")
        return value;
    }
    return nullptr;
};

RY_NAMESPACE_END
