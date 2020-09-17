#ifndef GAME_TIMER_H
#define GAME_TIMER_H

class Timer {
  private:
    long double time;
  public:
    Timer (long double);
    bool Tick(float);
};

#endif //GAME_TIMER_H
