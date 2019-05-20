//
//  RYComponent.hpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#ifndef RYComponent_hpp
#define RYComponent_hpp

#include "ccry-util.h"

#define RY_COMPONENT_ID_DECLARE(__ID__)  public: constexpr static RYComponentId __ID__ = "RYComponentId_"#__ID__;

RY_NAMESPACE_BEGIN

typedef const char* RYComponentId;

class RYEntity;
class RYSystem;

class RYComponent: public cocos2d::Ref {

friend class RYEntity;
friend class RYSystem;

public:
        
    virtual RYEntity *getEntity();
    
    CC_PROPERTY_READONLY_PASS_BY_REF(std::string, _identifier, Identifier);
    
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
