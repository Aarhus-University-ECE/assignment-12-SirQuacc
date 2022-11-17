#ifndef _DURATION_CLASS_HPP_
#define _DURATION_CLASS_HPP_


class Duration{
private:
    int time;
    int alarm;
    bool alarmHasBeenSet;
    bool checkAndUpdateAlarm();

public:
    Duration();
    ~Duration();
    void setDuration(int t);
    int getDuration();
    bool tick();
    bool addTick(int amount);
    void setAlarm(int t);

    void startTimer();
};

#endif
