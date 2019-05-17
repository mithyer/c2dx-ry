//
//  RYSystem.hpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#ifndef RYSystem_hpp
#define RYSystem_hpp

#include "c2d-ry-util.h"

#include "RYEntity.hpp"
#include "RYComponent.hpp"

#define RY_CREATE_SYSTEM_FUNC(__TYPE__, __CMP__) \
static __TYPE__* create() \
{ \
    __CMP__ *cmp; \
    cmp = nullptr; \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet) \
    {\
        pRet->setTypeName(#__TYPE__);\
        pRet->_componentTypeName = #__CMP__\
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = nullptr; \
        return nullptr; \
    } \
}

RY_NAMESPACE_BEGIN

class RYSystem: public RYRef {
    
public:
    
    virtual void addComponentsInEntity(RYEntity *entity);
    
    virtual void update(double dt);
    
protected:
    
    std::string _componentTypeName;
    std::vector<RYComponent *> _components;
    
};

RY_NAMESPACE_END

#endif /* RYSystem_hpp */
