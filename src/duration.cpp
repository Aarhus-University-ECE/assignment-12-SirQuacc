#include "duration.hpp" //Because it's not compiled, it would need to be moved to this directory
#include <unistd.h>
#include <assert.h>

Duration::Duration(){
    time = 0;
    alarm = -1;
    alarmHasBeenSet = false;
}

Duration::~Duration(){}

void Duration::setDuration(int t){
    assert(t >= 0); //Precond, can't set a negative time.
    time = t;
}

int Duration::getDuration(){
    return time;
}

bool Duration::tick(){
    time++;
    return checkAndUpdateAlarm();
}

bool Duration::addTick(int amount){
    assert(amount >= 0); //Precond, add a negative time.
    time += amount;
    return checkAndUpdateAlarm();
}

void Duration::setAlarm(int t){
    assert(t >= time); //Can't have an alarm in the past
    alarm = t;
    alarmHasBeenSet = true;
}

bool Duration::checkAndUpdateAlarm(){
    if(time > alarm && alarmHasBeenSet == true){
        alarm = -1;
        alarmHasBeenSet = false;
        return true;
    } 
    else return false;
}
/*
while(true){ //Keep running until destroyed
        sleep(1); //Sleep the thread for one second, when it wakes up, increment time with 1 (second). Rinse repeat
        time++;
    }
    */