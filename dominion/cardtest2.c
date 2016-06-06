/***************************************************
This will test the functionality of the great_hall card
****************************************************/
#include "dominion.h"

int testGreatHall(int* failed){
    struct gameState g;

    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute}; 
    int r = initializeGame(2, k, 5, &g);
    int cards = g.handCount[0];
    int actions = g.numActions;
    g.hand[0][0] = great_hall;

    cardEffect(0, 0, 0, 0, &g);
        //Only card name and state matter for this call
    myassert(failed, cards == g.handCount[0], "great_hall should give 1 more card");
    myassert(failed, actions == g.numActions, "great_hall should give 1 more action");
 
    return 0;
}
