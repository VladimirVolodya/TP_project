#include "Timer/Timer.h"

Timer::Timer(long double signal_time) : time(signal_time) {}

bool Timer::Tick(float tick_time) {
    time -= tick_time;
    return time <= 0;
}
