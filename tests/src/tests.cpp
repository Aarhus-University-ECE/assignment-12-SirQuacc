#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

extern "C++" {
    #include "duration.hpp"
}


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 
TEST_CASE("duration_test"){   
    Duration* dur = new Duration();
    int checkTime = dur->getDuration();
    REQUIRE(checkTime == 0);
    dur->setDuration(15);
    checkTime = dur->getDuration();
    REQUIRE(checkTime == 15);
    dur->setDuration(22);
    checkTime = dur->getDuration();
    REQUIRE(checkTime == 22);
    dur->setDuration(0);
    checkTime = dur->getDuration();
    REQUIRE(checkTime == 0);
    // Above is first batch of test cases (task d)

    dur->tick(); //We don't care about return value yet
    checkTime = dur->getDuration();
    REQUIRE(checkTime == 1);
    dur->tick();
    checkTime = dur->getDuration();
    REQUIRE(checkTime == 2);
    dur->addTick(5);
    checkTime = dur->getDuration();
    REQUIRE(checkTime == 7);
    dur->setDuration(0);
    checkTime = dur->getDuration();
    REQUIRE(checkTime == 0);
    //Second batch of test cases (task f)

    dur->setAlarm(2);
    REQUIRE(dur->tick() == false);
    dur->tick();
    REQUIRE(dur->tick() == true);
    dur->setDuration(0);
    dur->addTick(5);
    REQUIRE(dur->tick() == false); //Test the bool condition of not having set an alarm
    //Third batch of test cases (task g)
    delete dur;
    //For task h, I can't really include this, as it's implemented with assert(), it would stop the test program. But it does work(tested myself)




}
