//
//  Component.hpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#ifndef Component_hpp
#define Component_hpp

#include "ccry-util.h"


RY_NAMESPACE_BEGIN

typedef const char* ComponentId;

class Entity;
class System;

class Component: public cocos2d::Ref {

friend class Entity;
friend class System;

public:
        
    virtual Entity *getEntity();
    
    CC_PROPERTY_READONLY(ComponentId, _identifier, Identifier);
    
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
