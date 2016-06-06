/***************************************************
This will test the functionality of the scoreFor function
****************************************************/
#include <stdio.h>
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

    for(r = 0; r < g.handCount[1]; r++)
        printf("In hand: %d\n", g.hand[1][r]);

    for(r = 0; r < g.discardCount[1]; r++)
        printf("In discard: %d\n", g.discard[1][r]);
    
    for(r = 0; r < g.deckCount[1]; r++)
        printf("In deck: %d\n", g.deck[1][r]);

    printf("Score is: %d\n", scoreFor(1, &g));

    myassert(failed, scoreFor(1, &g) == 9, "Score Should be 9");

    g.whoseTurn = 1;
    g.numBuys = 1;
    g.coins = 10;
    //(g.supplyCount)[p] = 1;
    buyCard(province, &g);
    
    printf("Score is: %d\n", scoreFor(1, &g));
    myassert(failed, scoreFor(1, &g) == 15, "Score Should be 15");


    return 0;
}
