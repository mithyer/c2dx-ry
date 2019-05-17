//
//  RYComponent.hpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#ifndef RYComponent_hpp
#define RYComponent_hpp

#include "c2d-ry-util.h"
#include "RYRef.hpp"

RY_NAMESPACE_BEGIN

class RYEntity;
class RYSystem;

struct RYComponentIdentifier {
    
    CC_PROPERTY_READONLY_PASS_BY_REF(std::string, _name, Name)
    
public:
    
    RYComponentIdentifier(const std::string& name) {
        _name = name;
    };

};

class RYComponent: public RYRef {

friend class RYEntity;
friend class RYSystem;

public:
    
    RY_CREATE_FUNC(RYComponent);
    
    virtual RYEntity *getEntity();
    
protected:
    
    RYComponent();
    
    virtual ~RYComponent();

    virtual void setEntity(RYEntity *);
    
    bool _needDestroy;
    
private:
    
    RYEntity *_entity;
};
    
    
    
RY_NAMESPACE_END

#endif /* RYComponent_hpp */
