/***************************************************
This will test the functionality of the isGameOver function
****************************************************/
#include "dominion.h"

int testIsGameOver(int* failed){
    struct gameState g;

    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

    int r = initializeGame(2, k, 5, &g);

    g.supplyCount[province] = 0;
    
    myassert(failed, isGameOver(&g) == 1, "Game should be over");

    g.supplyCount[province] = 8;
    
    myassert(failed, isGameOver(&g) == 0, "Game should not be over");


    return 0;
}
