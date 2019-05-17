//
//  RYRef.hpp
//  Vendor
//
//  Created by ray on 2019/5/17.
//

#ifndef RYRef_hpp
#define RYRef_hpp

#include "c2d-ry-util.h"

#define RY_CREATE_FUNC(__TYPE__) \
static __TYPE__* create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet) \
        {\
        pRet->setTypeName(#__TYPE__);\
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

class RYRef: public cocos2d::Ref {
    
    

    
    
};

RY_NAMESPACE_END




#endif /* RYRef_hpp */
