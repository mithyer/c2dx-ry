//
//  RYEvent.hpp
//  Mine-mobile
//
//  Created by ray on 2019/5/17.
//

#ifndef RYEvent_hpp
#define RYEvent_hpp

#include "c2d-ry-util.h"


#define RY_CREATE_EVENT(__CLASS__, __NAME__) \
[]{ \
    __CLASS__ *instance; \
    instance = nullptr; \
    return ccry::RYEvent(#__CLASS__"_"#__NAME__); \
}


RY_NAMESPACE_BEGIN

class RYEvent {
    
public:
    
    RYEvent(const std::string& name);
    
private:
    
    std::string _name;
    
};

RY_NAMESPACE_END

#endif /* RYEvent_hpp */
