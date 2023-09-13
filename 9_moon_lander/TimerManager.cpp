#include "TimerManager.h"
#include <tiled/GameField.h>

TimerManager::TimerManager(GameField *field_) : field(field_) { }

void TimerManager::enableTimer() {

    field->enableTimer();
}

void TimerManager::disableTimer() {

    field->disableTimer();
}
