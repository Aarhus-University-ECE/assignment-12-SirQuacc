#include "duration.hpp" //Because it's not compiled, it would need to be moved to this directory
#include <unistd.h>
#include <assert.h>

Duration::Duration(){ //Init the variable
    time = 0;
    alarm = -1;
    alarmHasBeenSet = false;
}

Duration::~Duration(){} //Destroy variable

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
    assert(amount >= 0); //Precond, don't add a negative time.
    time += amount; //Increment time by given amount
    return checkAndUpdateAlarm();
}

void Duration::setAlarm(int t){
    assert(t >= time); //Can't have an alarm in the past
    alarm = t;
    alarmHasBeenSet = true;
}

bool Duration::checkAndUpdateAlarm(){ //return bool for checking alarm condition, and reset alarm if it is reached
    if(time > alarm && alarmHasBeenSet == true){
        alarm = -1;
        alarmHasBeenSet = false;
        return true;
    } 
    else return false;
}

