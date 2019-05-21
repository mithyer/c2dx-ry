//
//  RYEventCenter.hpp
//  Mine-mobile
//
//  Created by ray on 2019/5/20.
//

#ifndef RYEventCenter_hpp
#define RYEventCenter_hpp


#include "ccry-util.h"
#include "RYEvent.hpp"


RY_NAMESPACE_BEGIN

class RYEvent;

typedef cocos2d::EventListener *RYEventObserver;

class RYEvent;

class RYEventCenter {
    
public:
    
    static RYEventCenter *getInstance();
    
    RYEventObserver addObserver(RYEvent::EventName eventName, const std::function<void(RYEvent *)>& callback, int priority = 1);
    
    void postEvent(RYEvent *event);

    void removeEvents(RYEvent::EventName eventName);
    
    void removeEvent(RYEventObserver observer);
    
protected:
    
    RYEventCenter();
    
    //std::unordered_map<RYEventName, std::unordered_map<RYEventObserver, RYEvent *> *> _eventMap;
};

RY_NAMESPACE_END

#endif /* RYEventCenter_hpp */
