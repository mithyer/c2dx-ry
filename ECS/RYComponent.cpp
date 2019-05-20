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
    return _entity;
};


const std::string& RYComponent::getIdentifier() const {
    return _identifier;
}

RY_NAMESPACE_END
