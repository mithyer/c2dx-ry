//
//  RYEventCenter.cpp
//  Mine-mobile
//
//  Created by ray on 2019/5/20.
//

#include "RYEventCenter.hpp"


RY_NAMESPACE_BEGIN

static RYEventCenter *s_eventCenter = nullptr;

RYEventCenter *RYEventCenter::getInstance() {
    
    if (nullptr == s_eventCenter) {
        static std::mutex mutext;
        mutext.lock();
        if (nullptr == s_eventCenter) {
            s_eventCenter = new RYEventCenter();
            cocos2d::Director::getInstance()->getEventDispatcher();
        }
        mutext.unlock();
    }
    return s_eventCenter;
}

RYEventObserver addObserver(RYEvent::EventName eventName, const std::function<void(RYEvent *)>& callback, int priority = 1) {

    cocos2d::EventListener *listener = cocos2d::EventListenerCustom::create(eventName, [&](cocos2d::EventCustom *ccEvent) {
        auto event = static_cast<RYEvent *>(ccEvent->getUserData());
        callback(event);
    });
    
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, priority);
    
    return listener;
}

void RYEventCenter::postEvent(RYEvent *event) {
    
    auto eventName = event->_eventName;
    RY_ASSERT(eventName.size() > 0, "event has no name");
    
    cocos2d::EventCustom ccEvent(eventName);
    ccEvent.setUserData(event);
    
    event->retain();
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&ccEvent);
    event->release();
}

void RYEventCenter::removeEvents(RYEvent::EventName eventName) {
    
    cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(eventName);
}

void RYEventCenter::removeEvent(RYEventObserver observer) {
    
    cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(observer);
}

RY_NAMESPACE_END
