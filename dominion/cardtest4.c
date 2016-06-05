/***************************************************
This will test the functionality of the adventurer card
****************************************************/
#include "dominion.h"

int testAdventurer(int* failed){
    struct gameState g;
    int i;
    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute}; 
    int r = initializeGame(2, k, 5, &g);
    g.whoseTurn = 0;
    int cards = g.handCount[0];
    int actions = g.numActions; 
    int treasureCards = 0;
    int newTreasureCards = 0;

    for(i = 0; i < cards; i++)
        if (g.hand[0][i] == copper || g.hand[0][i] == silver || g.hand[0][i] == gold)
            treasureCards++;

    cardEffect(smithy, 0, 0, 0, &g, 0, &r);
        //Only card name and state matter for this call
    myassert(failed, cards+1 == g.handCount[0], "Adventurer should give you 2 cards");
    myassert(failed, actions-1 == g.numActions, "Adventurer should not give you an action");
    for(i = 0; i < cards; i++)
        if (g.hand[0][i] == copper || g.hand[0][i] == silver || g.hand[0][i] == gold)
            newTreasureCards++;
    myassert(failed, treasureCards+2 == newTreasureCards, "Adventurer should give you two treasure cards");


    return 0;
}
