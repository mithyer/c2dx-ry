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

RYEventObserver RYEventCenter::addObserver(RYEventName eventName, const std::function<void(RYEventUserInfo)>& callback, int priority) {

    cocos2d::EventListener *listener = cocos2d::EventListenerCustom::create(std::string("RYEventCenter.") + eventName, [&](cocos2d::EventCustom *ccEvent) {
        auto userInfo = static_cast<std::unordered_map<std::string, void *> *>(ccEvent->getUserData());
        callback(*userInfo);
    });
    
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, priority);
    
    return listener;
}

void RYEventCenter::postEvent(RYEventName eventName, RYEventUserInfo userInfo) {
    

    cocos2d::EventCustom ccEvent(std::string("RYEventCenter.") + eventName);
    ccEvent.setUserData((void *)&userInfo);
    
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&ccEvent);
}

void RYEventCenter::removeEvents(RYEventName eventName) {
    
    cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(eventName);
}

void RYEventCenter::removeEvent(RYEventObserver observer) {
    
    cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(observer);
}

RY_NAMESPACE_END
