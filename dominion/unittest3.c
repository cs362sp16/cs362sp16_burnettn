/***************************************************
This will test the functionality of the scoreFor function
****************************************************/
#include "dominion.h"

int testScoreFor(int* failed){
    struct gameState g;

    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

    int r = initializeGame(2, k, 5, &g);

    g.whoseTurn = 1;
    g.numBuys = 1;
    g.coins = 10;
    //(g.supplyCount)[p] = 1;
    buyCard(province, &g);
    
    myassert(failed, scoreFor(1, &g) == 11, "Score Should be 11");

    g.whoseTurn = 1;
    g.numBuys = 1;
    g.coins = 10;
    //(g.supplyCount)[p] = 1;
    buyCard(province, &g);
    
    myassert(failed, scoreFor(1, &g) == 19, "Score Should be 19");


    return 0;
}
