//
//  RYCountdown.hpp
//  Mine-mobile
//
//  Created by ray on 2019/5/21.
//

#ifndef RYCountdown_hpp
#define RYCountdown_hpp

#include "ccry-util.h"

RY_NAMESPACE_BEGIN

class Countdown {
    
public:
    
    static Countdown *create(float duration, int repeatTime, const std::function<void(int)>& onceOverCallback);
    
    void update(float dt);
    
    void resume();
    
    void pause();
    
    void reset();
    
    bool isPaused();
    
protected:
    
    float _duration;
    
    int _repeatTime;

    
    float _countdown;
    
    bool _foreverRepeat;
    
    int _repeatTimeLeft;
    
    bool _paused;
    

    std::function<void(int)> _onceOverCallback;
    
};





RY_NAMESPACE_END

#endif /* RYCountdown_hpp */
