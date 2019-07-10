//
//  RYSystem.cpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#include "RYSystem.hpp"

RY_NAMESPACE_BEGIN


const std::vector<Component *>& System::addComponentsInEntity(Entity *entity) {
    _componentsAdded.clear();
    for (auto pair : entity->_cmpMap) {
        auto cmp = pair.second;
        if (cmp->getTypeName() == _componentTypeName) {
            auto res = _components.insert(cmp);
            if (res.second) {
                cmp->retain();
                _componentsAdded.push_back(cmp);
            }
        }
    }
    return _componentsAdded;
}

const std::vector<Component *>& System::checkIfComponentsNeedDestroy() {
    _componentsWillDestroy.clear();
    auto cmps = _components;
    for (auto it = cmps.begin(); it != cmps.end(); ++it) {
        auto cmp = *it;
        if (cmp->_needDestroy) {
            cmp->_entity->_cmpMap.erase(cmp->_identifier);
            cmp->release();
            _components.erase(cmp);
            _componentsWillDestroy.push_back(cmp);
        }
    }
    return _componentsWillDestroy;
}

void System::update(double dt) {
    checkIfComponentsNeedDestroy();
}

void System::removeAllComponents() {
    for (auto cmp : _components) {
        cmp->release();
    }
    _components.clear();
}

System::~System() {
    removeAllComponents();
}


RY_NAMESPACE_END
