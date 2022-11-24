#include "duration.hpp" 
#include <unistd.h>
#include <assert.h>

Duration::Duration(){ //Constructor, setting private variables to default values
    time = 0;
    alarm = -1;
    alarmHasBeenSet = false;
}

Duration::~Duration(){} //Destroy the object, nothing more

Duration::Duration(int t){ //Construct with a specific value, t, for the time variable
    assert(t >= 0); //Precond, can't set a negative time.
    time = t;
    alarm = -1;
    alarmHasBeenSet = false;
}

int Duration::getDuration(){ //get current time value
    return time;
}

bool Duration::tick(){ //increment time by 1, return alarm if exceeded
    time++;
    return checkAndUpdateAlarm();
}

bool Duration::tick(int amount){ //Increment time by a specific amount, t, return alarm if exceeded
    assert(amount >= 0); //Precond, don't add a negative time.
    time += amount; 
    return checkAndUpdateAlarm();
}

void Duration::setAlarm(int t){ //Set the alarm for a specific time, t.
    assert(t >= time); //Can't have an alarm in the past
    alarm = t;
    alarmHasBeenSet = true;
}

bool Duration::checkAndUpdateAlarm(){ //return bool for checking alarm condition, and reset alarm if it is reached
    if(alarmHasBeenSet == true && time > alarm){
        alarm = -1;
        alarmHasBeenSet = false;
        return true;
    } 
    else return false;
}

