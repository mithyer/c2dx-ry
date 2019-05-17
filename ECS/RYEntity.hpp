//
//  RYEntity.hpp
//  Vendor
//
//  Created by ray on 2019/5/16.
//

#ifndef RYEntity_hpp
#define RYEntity_hpp

#include "c2d-ry-util.h"
#include "RYComponent.hpp"

RY_NAMESPACE_BEGIN

class RYSystem;

class RYEntity: public RYRef {
        
    friend class RYSystem;
    
public:
    
    RY_CREATE_FUNC(RYComponent);
    
    virtual void addComponent(RYComponent *cmp, const RYComponentIdentifier& identifier);
    
    virtual RYComponent *component(const RYComponentIdentifier& identifier);
    
    
private:
    
    std::map<std::string, RYComponent*> _cmpMap;
    

};

RY_NAMESPACE_END



#endif /* RYEntity_hpp */
