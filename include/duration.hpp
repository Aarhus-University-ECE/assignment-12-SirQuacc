#ifndef _DURATION_HPP_
#define _DURATION_HPP_

class Duration{
private:
    int time;
    int alarm;
    bool alarmHasBeenSet;
    bool checkAndUpdateAlarm();

public:
    Duration();
    ~Duration();
    Duration(int t);
    int getDuration();
    bool tick();
    bool tick(int amount);
    void setAlarm(int t);
};

#endif
