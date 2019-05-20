//
//  RYEntity.hpp
//  Vendor
//
//  Created by ray on 2019/5/16.
//

#ifndef RYEntity_hpp
#define RYEntity_hpp

#include "RYComponent.hpp"


RY_NAMESPACE_BEGIN

class RYSystem;

class RYEntity: public cocos2d::Ref {
        
    friend class RYSystem;
    
public:
        
    virtual void addComponent(RYComponent *cmp, RYComponentId identifier);
    
    virtual RYComponent *component(RYComponentId identifier);
    
    
private:
    
    std::map<std::string, RYComponent*> _cmpMap;
    

};

RY_NAMESPACE_END



#endif /* RYEntity_hpp */
