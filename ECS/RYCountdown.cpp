//
//  RYCountdown.cpp
//  Mine-mobile
//
//  Created by ray on 2019/5/21.
//

#include "RYCountdown.hpp"


RY_NAMESPACE_BEGIN


Countdown *Countdown::create(float duration, int repeatTime, const std::function<void(int)>& onceOverCallback) {
    auto cd = new Countdown();
    cd->_duration = duration;
    cd->_repeatTime = repeatTime;
    
    cd->_countdown = duration;
    if (repeatTime <= 0) {
        cd->_foreverRepeat = true;
        cd->_repeatTimeLeft = -999;
    } else {
        cd->_foreverRepeat = false;
        cd->_repeatTimeLeft = repeatTime;
    }
    cd->_paused = true;

    cd->_onceOverCallback = onceOverCallback;
    return cd;
}

void Countdown::update(float dt) {
    
    if (_paused || (!_foreverRepeat && _repeatTimeLeft <= 0)) {
        return;
    }
    _countdown -= dt;
    if (_countdown <= 0) {
        _countdown += _duration;
        if (!_foreverRepeat) {
            --_repeatTimeLeft;
        }
        _onceOverCallback(_repeatTimeLeft);
    }
}

bool Countdown::isPaused() {
    
    return _paused;
}

void Countdown::pause() {
    
    _paused = true;
}

void Countdown::resume() {
    
    _paused = false;
}

void Countdown::reset() {
    
    _countdown = _duration;
    if (!_foreverRepeat) {
        _repeatTimeLeft = _repeatTime;
    }
    _paused = true;
}


RY_NAMESPACE_END
