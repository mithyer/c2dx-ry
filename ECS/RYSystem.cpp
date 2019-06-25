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
            if (std::find(_components.begin(), _components.end(), cmp) == _components.end()) {
                _components.push_back(cmp);
                cmp->retain();
                _componentsAdded.push_back(cmp);
            }
        }
    }
    return _componentsAdded;
}

const std::vector<Component *>& System::checkIfComponentsNeedDestroy() {
    _componentsWillDestroy.clear();
    for (auto it = _components.rbegin(); it != _components.rend(); ++it) {
        auto cmp = *it;
        if (cmp->_needDestroy) {
            cmp->_entity->_cmpMap.erase(cmp->_identifier);
            cmp->release();
            _components.erase(it.base());
            _componentsWillDestroy.push_back(cmp);
        }
    }
    return _componentsWillDestroy;
}

void System::update(double dt) {
    checkIfComponentsNeedDestroy();
}

System::~System() {
    for (auto cmp : _components) {
        cmp->release();
    }
    _components.clear();
}


RY_NAMESPACE_END
