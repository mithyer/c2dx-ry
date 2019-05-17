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
            _components.push_back(cmp);
        }
    }
}

void RYSystem::update(double dt) {
    
    for (auto it = _components.rbegin(); it != _components.rend(); ++it) {
        auto cmp = *it;
        if (cmp->_needDestroy) {
            _components.erase(it.base());
        }
    }
}

RY_NAMESPACE_END
