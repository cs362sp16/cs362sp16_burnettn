#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char** argv){
    srand(time(argv[1]));
    int random = rand();
    //int random = atoi(argv[1]);
    printf("running with: %d\n", random);

    int result = test_adventurer(random);

    return 0;
}
