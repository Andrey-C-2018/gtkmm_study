#pragma once

struct ITimerManager {

    virtual void enableTimer() = 0;
    virtual void disableTimer() = 0;
    virtual ~ITimerManager() = default;
};
