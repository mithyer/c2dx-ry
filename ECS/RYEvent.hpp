//
//  RYEvent.hpp
//  Mine-mobile
//
//  Created by ray on 2019/5/21.
//

#ifndef RYEvent_hpp
#define RYEvent_hpp

#include "ccry-util.h"

#define RY_EVENT_CREATE_FUNC(__CLS__)  public: constexpr static ccry::EventName Name = "RYEventName_"#__CLS__;\
static __CLS__* create() \
{ \
    __CLS__ *pRet = new(std::nothrow) __CLS__(); \
    if (pRet) \
    {\
        pRet->_eventName = __CLS__::Name;\
        pRet->setTypeName(#__CLS__);\
        pRet->autorelease();\
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

typedef const char* EventName;

class Event: public cocos2d::Ref {
    
public:
    

    friend class EventCenter;
    
protected:
    
    std::string _eventName;
    
};

RY_NAMESPACE_END

#endif /* RYEvent_hpp */
