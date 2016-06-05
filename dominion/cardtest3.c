/***************************************************
This will test the functionality of the smithy card
****************************************************/
#include "dominion.h"

int testSmithy(int* failed){
    struct gameState g;

    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute}; 
    int r = initializeGame(2, k, 5, &g);
    g.whoseTurn = 0;
    int cards = g.handCount[0];
    int actions = g.numActions; 

    cardEffect(smithy, 0, 0, 0, &g, 0, &r);
        //Only card name and state matter for this call
    myassert(failed, cards+2 == g.handCount[0], "Smithy should give you 3 cards");
    myassert(failed, actions-1 == g.numActions, "Smithy should not give you an action");


    return 0;
}
