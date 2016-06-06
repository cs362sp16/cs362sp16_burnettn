#include "test_driver.h"

int myassert(int* failed, int b, char* msg){
    if(b==0){
        printf("FAILED ASSERTION: %s\n", msg);
        (*failed) += 1;
    }
}
void checkasserts(int failed){
    if(!failed){
        printf("ALL TESTS SUCCESSFULLY COMPLETED.\n");
    }
}

int main(){
    int failed = 0;
    testPeople(&failed);
    testGetCost(&failed);
    testBuyCard(&failed);
    testScoreFor(&failed);
    testIsGameOver(&failed);
    
    testVillage(&failed);
    testGreatHall(&failed);
    //testSmithy(&failed);
    //testAdventurer(&failed);

    checkasserts(failed);

    return 0;
}

