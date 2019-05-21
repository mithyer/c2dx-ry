//
//  RYSystem.hpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#ifndef RYSystem_hpp
#define RYSystem_hpp

#include "RYEntity.hpp"
#include "RYComponent.hpp"


#define RY_CREATE_SYSTEM_FUNC(__SYSCLS__, __CMPCLS__) \
static __SYSCLS__* create() \
{ \
    __CMPCLS__ *cmp; \
    cmp = nullptr; \
    __SYSCLS__ *pRet = new(std::nothrow) __SYSCLS__(); \
    if (pRet) \
    {\
        pRet->setTypeName(#__SYSCLS__);\
        pRet->_componentTypeName = #__CMPCLS__\
        pRet->autorelease();\
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

class RYSystem: public cocos2d::Ref {
    
public:
    
    virtual void addComponentsInEntity(RYEntity *entity);
    
    virtual void update(double dt);
    
    ~RYSystem();
    
protected:
    
    std::string _componentTypeName;
    std::vector<RYComponent *> _components;
};

RY_NAMESPACE_END

#endif /* RYSystem_hpp */
