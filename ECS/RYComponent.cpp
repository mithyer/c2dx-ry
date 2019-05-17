//
//  CCRYComponent.cpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#include "RYComponent.hpp"
#include "RYEntity.hpp"

RY_NAMESPACE_BEGIN


RYComponent::RYComponent():
_entity(nullptr) {
    
};

RYComponent::~RYComponent() {
    if (nullptr != _entity) {
        RY_ASSERT(RY_REF_EXIST(_entity), "WTF")
        _entity->release();
    }
};

void RYComponent::setEntity(RYEntity *entity) {
    RY_ASSERT(nullptr == _entity, "has entity");
    _entity = entity;
    _entity->retain();
}

RYEntity *RYComponent::getEntity() {
    
    if (nullptr == _entity) {
        return nullptr;
    }
    
    if (!RY_REF_EXIST(_entity)) {
        _entity = nullptr;
    }
    return _entity;
};


RY_NAMESPACE_END
