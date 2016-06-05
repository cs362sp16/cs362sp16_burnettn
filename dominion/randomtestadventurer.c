#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1

int main(int argc, char** argv)
{
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int i, test, rand_seed, players, x, num_treasure,new_num_treasure, play,  passes, fails, totalpass, totalfail;

    struct gameState state;
    if(argc != 2)
    {
        printf("Usage: ./test_random [rand seed]\n");
        return 0;
    }
    totalpass = 0;
    totalfail = 0;
    srand(time(NULL));

    //Run max number of tests
    for(test = 0; test < MAX_TESTS; test++)
    {
        //Get a rand seed and number of players
        rand_seed = atoi(argv[1]);
        //Gets a rand between 2 and max players
        players = (rand() % (MAX_PLAYERS -1)) + 2;
        initializeGame(players, k, rand_seed, &state);

            passes = 0;
            fails = 0;

        //Loop to go through each turn
        for(i = 0; i < players; i++)
        {
            state.deckCount[i] = (rand() % MAX_DECK) + 1;
            state.discardCount[i] = (rand() % MAX_DECK) + 1 ;
            state.handCount[i] = (rand() % MAX_HAND) + 1;

            num_treasure = 0;

            //Randomize either playing adventurer or random card
            play = rand() % 2;

            //Each turn gets a random fill of cards
            for(x = 0; x < state.handCount[i]; x++)
            {
                //printf("It is: %d\n", state.handCount[i]);
                state.hand[i][x] = rand() % 28;
                //This if statement counts the treasure cards
                if(state.hand[i][x] == copper ||
                        state.hand[i][x] == silver ||
                        state.hand[i][x] == gold)
                {
                    num_treasure++;
                }
            }

            //If play == 1 we will play adventurer
            if(play)
            {   
                cardEffect(adventurer, 1, 1, 1, &state, 0, 0);
                new_num_treasure = 0;
                //Check to see if we have 2 new treasure cards
                for(x = 0; x < state.handCount[i]; x++)
                {
                    //This if statement counts the treasure cards
                    if(state.hand[i][x] == copper ||
                            state.hand[i][x] == silver ||
                            state.hand[i][x] == gold)
                    {
                        new_num_treasure++;
                    }
                }
                if(new_num_treasure - num_treasure != 2)
                {
                    fails++;
                }
                else
                {
                    passes++;
                }
            }
            else
            {
                cardEffect(state.hand[i][rand() % state.handCount[i]], 1, 1, 1, &state, 0, 0);
            }
        } 
        //If the card did what it was supposed to atleast once, and did not fail once
        if(!fails && passes){
            totalpass++;
        }
        //If the card ever failed
        else if(fails){
            totalfail++;
        }
        //If the card never failed or passed (was never played), the round does not count
        else{}
    }    

    printf("\n--------------------------------------\n ADVENTURER:\n--------------------------------------\n PASSES: %d\n FAILS: %d \n PASS RATE: %f\n--------------------------------------\n", totalpass, totalfail, ((float)totalpass)/((float)totalfail + (float)totalpass));

    return 0;
}
