//
//  CCComponent.cpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#include "RYComponent.hpp"
#include "RYEntity.hpp"

RY_NAMESPACE_BEGIN


Component::Component():
_entity(nullptr) {
    
};

Component::~Component() {
    if (nullptr != _entity) {
        RY_ASSERT(RY_REF_EXIST(_entity), "WTF")
        _entity->release();
    }
};

void Component::setEntity(Entity *entity) {
    RY_ASSERT(nullptr == _entity, "has entity");
    _entity = entity;
    _entity->retain();
}

Entity *Component::getEntity() {
    return _entity;
};


ComponentId Component::getIdentifier() const {
    return _identifier;
}

void Component::setNeedDestroy() {
    _needDestroy = true;
}

RY_NAMESPACE_END
