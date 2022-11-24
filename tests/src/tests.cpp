#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

extern "C++" {
    #include "duration.hpp"
}

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 
TEST_CASE("duration_test"){   
    Duration* dur = new Duration();
    REQUIRE(dur->getDuration() == 0);
    delete dur;

    dur = new Duration(15);
    REQUIRE(dur->getDuration() == 15);
    delete dur;

    dur = new Duration(22);
    REQUIRE(dur->getDuration() == 22);
    delete dur;
    // Above is first batch of test cases (task d)
    
    dur = new Duration();
    dur->tick(); //We don't care about return value yet
    REQUIRE(dur->getDuration() == 1);
    dur->tick();
    REQUIRE(dur->getDuration() == 2);
    dur->tick(5);
    REQUIRE(dur->getDuration() == 7);
    delete dur;

    dur = new Duration();
    REQUIRE(dur->getDuration() == 0);
    //Second batch of test cases (task f)
    
    dur->setAlarm(2);
    REQUIRE(dur->tick() == false);
    dur->tick();
    REQUIRE(dur->tick() == true);
    delete dur;

    dur = new Duration();
    dur->tick(5);
    REQUIRE(dur->tick() == false); //Test the bool condition of not having set an alarm
    //Third batch of test cases (task g)
    delete dur;

    //For task h, I can't really include this, as it's implemented with assert(), it would stop the test program. But it does work(tested myself)
}
