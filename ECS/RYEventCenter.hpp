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

class Event;

typedef cocos2d::EventListener *EventObserver;

class Event;

class EventCenter {
    
public:
    
    static EventCenter *getInstance();
    
    EventObserver addObserver(EventName eventName, const std::function<void(Event *)>& callback, int priority = 1);
    
    void postEvent(Event *event);

    void removeEvents(EventName eventName);
    
    void removeEvent(EventObserver observer);
    
protected:
    
    EventCenter();
    
    static void initCenter();
    
    //std::unordered_map<RYEventName, std::unordered_map<RYEventObserver, RYEvent *> *> _eventMap;
};

RY_NAMESPACE_END

#endif /* RYEventCenter_hpp */
