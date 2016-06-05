#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dominion.h"

char* get_name(int card){
    char* name = malloc(sizeof(char)*20);
    if(card == curse)
        strcpy(name, "curse");
    else if(card == estate)
        strcpy(name, "estate");
    else if(card == duchy)
        strcpy(name, "duchy");
    else if(card == province)
        strcpy(name, "province");
    else if(card == copper)
        strcpy(name, "copper");
    else if(card == silver)
        strcpy(name, "silver");
    else if(card == gold)
        strcpy(name, "gold");
    else if(card == adventurer)
        strcpy(name, "adventurer");
    else if(card == council_room)
        strcpy(name, "council_room");
    else if(card == feast)
        strcpy(name, "feast");
    else if(card == gardens)
        strcpy(name, "gardens");
    else if(card == mine)
        strcpy(name, "mine");
    else if(card == remodel)
        strcpy(name, "remodel");
    else if(card == smithy)
        strcpy(name, "smithy");
    else if(card == village)
        strcpy(name, "village");
    else if(card == baron)
        strcpy(name, "baron");
    else if(card == great_hall)
        strcpy(name, "great_hall");
    else if(card == minion)
        strcpy(name, "minion");
    else if(card == steward)
        strcpy(name, "steward");
    else if(card == tribute)
        strcpy(name, "tribute");
    else if(card == ambassador)
        strcpy(name, "ambassador");
    else if(card == cutpurse)
        strcpy(name, "cutpurse");
    else if(card == embargo)
        strcpy(name, "embargo");
    else if(card == outpost)
        strcpy(name, "outpost");
    else if(card == salvager)
        strcpy(name, "salvager");
    else if(card == sea_hag)
        strcpy(name, "sea_hag");
    else if(card == treasure_map)
        strcpy(name, "treasure_map");
    else
        strcpy(name, "OUT OF RANGE");

    return name;
}

void play(int handLoc, struct gameState* p)
{
    int card = handCard(handLoc, p);
    char* name = get_name(card);
    printf("%d plays: %s\n", p->whoseTurn, name);
    free(name);

    if(card == adventurer || 
       card == council_room ||
       card == gardens ||
       card == smithy ||
       card == village ||
       card == great_hall ||
       card == tribute ||
       card == cutpurse ||
       card == outpost ||
       card == sea_hag ||
       card == treasure_map)
        playCard(handLoc, -1, -1, -1, p);
    else if(card == feast)
        playCard(handLoc, 0, -1, -1, p);
    else if(card == mine)
        playCard(handLoc, copper, silver, -1, p);
    else if(card == remodel)
        playCard(handLoc, copper, estate, -1, p);
    else if(card == baron)
        playCard(handLoc, 0, -1, -1, p);
    else if(card == minion)
        playCard(handLoc, 1, -1, -1, p);
    else if(card == steward)
        playCard(handLoc, 2, -1, -1, p);
    else if(card == ambassador)
        playCard(handLoc, 0, 0, -1, p);
    else if(card == embargo)
        playCard(handLoc, 0, -1, -1, p);
    else if(card == salvager)
        playCard(handLoc, 0, -1, -1, p);

}

int bought(int not_bought[10], struct gameState* p, int card)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        if(card == not_bought[i])
        {
            not_bought[i] = 100;
            return 0;
        }
    }
    return 1;
}

int played(int not_played[10], struct gameState* p, int card)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        if(card == not_played[i])
        {
            not_played[i] = 100;
            return 0;
        }
    }
    return 1;
}

void buy_card(struct gameState* p, int not_bought[10], int k[10])
{

    int money = 0, j;
    for(j = 0; j < numHandCards(p); j++)
    {
        if(handCard(j,p) == copper)
        {
            playCard(j, -1, -1, -1, p);
            money++;
        }    
        if(handCard(j,p) == silver)
        {
            playCard(j, -1, -1, -1, p);
            money += 2;
        }
        if(handCard(j,p) == gold)
        {
            playCard(j, -1, -1, -1, p);
            money += 3;
        }
    }
    
    if(money > 7)
    {
        buyCard(province, p);
        printf("%d Bought province\n", p->whoseTurn);
    }
    else if(money > 5)
    {
        for(j = 0; j < 10; j++)
        {
            if(!(bought(not_bought, p, k[j])))
            {
                buyCard(k[j], p);
                printf("%d Bought %s\n", p->whoseTurn, get_name(k[j]));
                j = 10;
            }
        }
    }
    else if(money > 5)
    {
        buyCard(gold, p);
        printf("%d Bought gold\n", p->whoseTurn);
    }
    else if(money > 2)
    {
        buyCard(silver, p);
        printf("%d Bought silver\n", p->whoseTurn);
    }
    else
    {
        buyCard(copper, p);
        printf("%d Bought copper\n", p->whoseTurn);
    }
}

void print_state(struct gameState* p, int players)
{
    int i, j,score, winner[players];

    getWinners(winner, p);
    printf("Final gamestate:\n");
    for(i = 0; i < players; i++)
    {
        score = 0;
        printf("\nPlayer %d:\n", i);
        if(winner[i])
            printf("WINNER!\n");
        printf("    Cards:\n");
        for(j = 0; j < (p->deckCount)[i]; j++)
        {
            printf("%s, ", get_name((p->deck)[i][j]));
        }
        printf("\n    Score: %d\n", scoreFor(i, p));
    }
    

}

int main(int argc, char** argv){

    int i, j, random, boolean, players, temp, money, act_x, vil_x, action, buy;

    if(argc != 2)
    {
        printf("Usage: ./testdominion [random seed]");
        return 0;
    }
    else
    {
        random = atoi(argv[1]);
    }

    srand(random);

    struct gameState g;
    struct gameState* p = &g;

    int k[10];

    for(i = 0; i < 10; i++)
    {
        temp = (rand() % 20) + 7; 
        boolean = 1;
        for(j = 0; j < i; j++)
            if(k[j] == temp)
                boolean = 0;
        if(boolean)     //If the number does not already exist
            k[i] = temp;
        else            //If the number already exists in the array
            i--;
    }

    int not_bought[10];
    int not_played[10];

    for(i = 0; i < 10; i++)
    {
        not_bought[i] = k[i];
        not_played[i] = k[i];
    }

    players = (rand() % 3) + 2;

    int r = initializeGame(players, k, random, p);

    while(!isGameOver(p))        //Loop that continues for game
    {
        for(i = 0; i < players; i++)
        {                                           //Loop the loops through each player
            action = 1;
            buy = 1;
            money = 0;            
            while(action)             //Loop that continues for each players actions
            {
                vil_x = -1;
                act_x = -1;
                for(j = 0; j < numHandCards(p); j++)    //Loop runs through hand
                {
                    if(handCard(j, p) == village)
                    {
                        vil_x = j;
                        break;
                    }
                    else if(!played(not_played, p, handCard(j, p)))
                        act_x = j;
                }
                if(vil_x > -1)
                {
                    playCard(j, -1, -1, -1, p);
                    printf("Player %d played a village\n", j);
                }
                else if(act_x > -1)
                {
                    play(act_x, p);
                    action = 0;
                }
                else
                    action = 0;
            }

            buy_card(p, not_bought, k);

            endTurn(p);
        }
    }
    print_state(p, players);
    printf("\n");
    return 0;
}


