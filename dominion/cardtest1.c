/***************************************************
  This will test the functionality of the village card
 ****************************************************/
#include "dominion.h"

int testVillage(int* failed){
    struct gameState g;

    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute}; 
    int r = initializeGame(2, k, 5, &g);
    g.whoseTurn = 0;
    int cards = g.handCount[0];
    int actions = g.numActions; 

    cardEffect(village, 0, 0, 0, &g, 0, &r);
        //Only card name and state matter for this call
    myassert(failed, cards == g.handCount[0], "Village should give 1 more card");
    myassert(failed, actions+1 == g.numActions, "Village should give 2 more actions");



    return 0;
}
