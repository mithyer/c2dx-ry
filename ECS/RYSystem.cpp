//
//  RYSystem.cpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#include "RYSystem.hpp"

RY_NAMESPACE_BEGIN


void RYSystem::addComponentsInEntity(RYEntity *entity) {
    for (auto pair : entity->_cmpMap) {
        auto cmp = pair.second;
        if (cmp->getTypeName() == _componentTypeName) {
            if (std::find(_components.begin(), _components.end(), cmp) == _components.end()) {
                _components.push_back(cmp);
                cmp->retain();
            }
        }
    }
}

void RYSystem::update(double dt) {
    
    for (auto it = _components.rbegin(); it != _components.rend(); ++it) {
        auto cmp = *it;
        if (cmp->_needDestroy) {
            cmp->release();
            _components.erase(it.base());
        }
    }
}

RYSystem::~RYSystem() {
    for (auto cmp : _components) {
        cmp->release();
    }
    _components.clear();
}


RY_NAMESPACE_END
