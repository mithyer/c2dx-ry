//
//  RYEventCenter.cpp
//  Mine-mobile
//
//  Created by ray on 2019/5/20.
//

#include "RYEventCenter.hpp"


RY_NAMESPACE_BEGIN

static EventCenter *s_eventCenter = nullptr;

void EventCenter::initCenter() {
    s_eventCenter = new EventCenter();
}

EventCenter *EventCenter::getInstance() {
    
    static std::once_flag flag;
    if (nullptr == s_eventCenter) {
        std::call_once(flag, initCenter);
    }
    return s_eventCenter;
}

EventObserver addObserver(EventName eventName, const std::function<void(Event *)>& callback, int priority = 1) {

    cocos2d::EventListener *listener = cocos2d::EventListenerCustom::create(eventName, [&](cocos2d::EventCustom *ccEvent) {
        auto event = static_cast<Event *>(ccEvent->getUserData());
        callback(event);
    });
    
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, priority);
    
    return listener;
}

void EventCenter::postEvent(Event *event) {
    
    auto eventName = event->_eventName;
    RY_ASSERT(eventName.size() > 0, "event has no name");
    
    cocos2d::EventCustom ccEvent(eventName);
    ccEvent.setUserData(event);
    
    event->retain();
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&ccEvent);
    event->release();
}

void EventCenter::removeEvents(EventName eventName) {
    
    cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(eventName);
}

void EventCenter::removeEvent(EventObserver observer) {
    
    cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(observer);
}

RY_NAMESPACE_END
