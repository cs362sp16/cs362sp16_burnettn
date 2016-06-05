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
    int i, test, players, x, num_treasure,new_num_treasure, play,  passes, fails, totalpass, totalfail;

    int rand_seed = atoi(argv[1]);
    struct gameState state;
    totalpass = 0;
    totalfail = 0;
    srand(rand_seed);

    //Run max number of tests
    for(test = 0; test < MAX_TESTS; test++)
    {
        //Gets a rand between 2 and max players
        players = (rand() % (MAX_PLAYERS -1)) + 2;
        initializeGame(players, k, rand(), &state);

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

            //printf("Before: ");
            //fflush(stdout);

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
              //      printf("%d, ", state.hand[i][x]);
            //fflush(stdout);
                    num_treasure++;
                }
            }
            //printf(" - END\n");
            //fflush(stdout);

            //If play == 1 we will play adventurer
            if(play)
            {   
                if(rand() % 5 < 1)
                    state.deckCount[i] = 0;
                cardEffect(adventurer, 1, i, 1, &state, 0, 0);
                new_num_treasure = 0;
                //Check to see if we have 2 new treasure cards
                //printf("After: ");
            //fflush(stdout);
                for(x = 0; x < state.handCount[i]; x++)
                {
                    //This if statement counts the treasure cards
                    if(state.hand[i][x] == copper ||
                            state.hand[i][x] == silver ||
                            state.hand[i][x] == gold)
                    {
               //         printf("%d, ", state.hand[i][x]);
            //fflush(stdout);
                        new_num_treasure++;
                    }
                }
                //printf(" - END2\n");
            //fflush(stdout);
                if(new_num_treasure - num_treasure != 2)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                cardEffect(state.hand[i][rand() % state.handCount[i]], 1, i, 1, &state, 0, 0);
            }
        } 
        //If the card did what it was supposed to atleast once, and did not fail once
        /*
        if(!fails && passes){
            //printf("1");
            //fflush(stdout);
            return 1;
        }
        //If the card ever failed
        else if(fails){
            //printf("0");
            //fflush(stdout);
            return 0;
        }
        */
        //If the card never failed or passed (was never played), we try again 
        //else
        //{
            test--;
        //}
    }    

    //printf("\n--------------------------------------\n ADVENTURER:\n--------------------------------------\n PASSES: %d\n FAILS: %d \n PASS RATE: %f\n--------------------------------------\n", totalpass, totalfail, ((float)totalpass)/((float)totalfail + (float)totalpass));

    return 0;
}
