//
//  RYEventCenter.hpp
//  Mine-mobile
//
//  Created by ray on 2019/5/20.
//

#ifndef RYEventCenter_hpp
#define RYEventCenter_hpp


#include "ccry-util.h"

#define RY_EVENT_NAME_DECLARE(__EVENT__)  public: constexpr static RYEventName __EVENT__ = "RYEventName_"#__EVENT__;


RY_NAMESPACE_BEGIN

typedef const char* RYEventName;

typedef const std::unordered_map<std::string, void *>& RYEventUserInfo;

typedef cocos2d::EventListener *RYEventObserver;

class RYEvent;

class RYEventCenter {
    
public:
    
    static RYEventCenter *getInstance();
    
    RYEventObserver addObserver(RYEventName eventName, const std::function<void(RYEventUserInfo)>& callback, int priority = 1);
    
    void postEvent(RYEventName eventName, RYEventUserInfo userInfo);

    void removeEvents(RYEventName eventName);
    
    void removeEvent(RYEventObserver observer);
    
protected:
    
    RYEventCenter();
    
    //std::unordered_map<RYEventName, std::unordered_map<RYEventObserver, RYEvent *> *> _eventMap;
};

RY_NAMESPACE_END

#endif /* RYEventCenter_hpp */
