//
//  Entity.hpp
//  Vendor
//
//  Created by ray on 2019/5/16.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "RYComponent.hpp"


RY_NAMESPACE_BEGIN

class System;

class Entity: public cocos2d::Ref {
        
    friend class System;
    
public:
        
    virtual void addComponent(Component *cmp, ComponentId identifier);
    
    virtual Component *component(ComponentId identifier);
    
    
protected:
    
    std::map<std::string, Component*> _cmpMap;
    

};

RY_NAMESPACE_END



#endif /* Entity_hpp */
