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
public: constexpr static const char* CMPName = #__CMPCLS__;\
static __SYSCLS__* create() \
{ \
    __CMPCLS__ *cmp; \
    cmp = nullptr; \
    __SYSCLS__ *pRet = new(std::nothrow) __SYSCLS__(); \
    if (pRet) \
    {\
        pRet->_componentTypeName = __SYSCLS__::CMPName;\
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

class System {
    
public:
    
    virtual const std::vector<Component *>& addComponentsInEntity(Entity *entity);

    virtual void update(double dt);
    
    virtual ~System();

protected:
    
    virtual const std::vector<Component *>& checkIfComponentsNeedDestroy();
    
    const char* _componentTypeName;
    
    std::vector<Component *> _components;
    
    std::vector<Component *> _componentsAdded;
    
    std::vector<Component *> _componentsWillDestroy;

};

RY_NAMESPACE_END

#endif /* RYSystem_hpp */
