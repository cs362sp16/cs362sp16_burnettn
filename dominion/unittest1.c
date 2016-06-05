/***************************************************
This will test the functionality of the getCost function
****************************************************/
#include "dominion.h"

int testGetCost(int* failed){
    myassert(failed, getCost(adventurer) == 6, "Adventurer should cost 6");
    myassert(failed, getCost(silver) == 3, "Silver should cost 3");
    myassert(failed, getCost(estate) == 2, "Estate should cost 2");

    return 0;
}
