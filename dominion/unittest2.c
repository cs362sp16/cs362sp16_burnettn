/***************************************************
This will test the functionality of the buyCard function
****************************************************/
#include "dominion.h"

int testBuyCard(int* failed){
    struct gameState g;

    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

    int r = initializeGame(2, k, 5, &g);

    g.whoseTurn = 1;
    g.numBuys = 1;
    g.coins = 10;
    (g.supplyCount)[curse] = 1;
    
    myassert(failed, supplyCount(curse, &g) == 1, "Supply count should be 1");
    myassert(failed, buyCard(curse, &g) == 0, "You can't buy a card when you should be able to");
    myassert(failed, supplyCount(curse, &g) == 0, "Supply count should be 0");
    myassert(failed, buyCard(curse, &g) != 0, "You bought a card with 0 in supply");

    return 0;
}
