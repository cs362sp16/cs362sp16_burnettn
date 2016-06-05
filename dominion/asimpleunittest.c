#include "test_driver.h"

int testPeople(int* failed) {
    
  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);

  myassert(failed, r == 0, "No duplicates, 2 players, should succeed");

  int k2[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,adventurer};

  r = initializeGame(2, k2, 5, &g);

  myassert(failed, r == -1,"Duplicate card in setup, should fail");

  r = initializeGame(200, k, 5, &g);

  myassert(failed, r == 0,"I should be allowed to play with a lot of people!");

  return 0;

}
