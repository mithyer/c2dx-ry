//
//  Component.hpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#ifndef Component_hpp
#define Component_hpp

#include "ccry-util.h"

#define RY_COMPONENT_ID_DECLARE(__ID__)  public: constexpr static ComponentId __ID__ = "ComponentId_"#__ID__;

RY_NAMESPACE_BEGIN

typedef const char* ComponentId;

class Entity;
class System;

class Component: public cocos2d::Ref {

friend class Entity;
friend class System;

public:
        
    virtual Entity *getEntity();
    
    CC_PROPERTY_READONLY_PASS_BY_REF(std::string, _identifier, Identifier);
    
protected:
    
    Component();
    
    virtual ~Component();

    virtual void setEntity(Entity *);
    
    bool _needDestroy;
    
private:
    
    Entity *_entity;
};
    
    
    
RY_NAMESPACE_END

#endif /* Component_hpp */
