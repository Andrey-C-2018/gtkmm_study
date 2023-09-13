#pragma once
#include "ITimerManager.h"

class GameField;

class TimerManager : public ITimerManager {
    GameField *field;

public:
    TimerManager(GameField *field);

    TimerManager(const TimerManager &obj) = default;
    TimerManager(TimerManager &&obj) = default;
    TimerManager &operator=(const TimerManager &obj) = default;
    TimerManager &operator=(TimerManager &&obj) = default;

    void enableTimer() override;

    void disableTimer() override;

    ~TimerManager() override = default;
};
