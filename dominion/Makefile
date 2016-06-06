#CFLAGS = -Wall -fpic -coverage -lm
CFLAGS = -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

test_driver.o: test_driver.c
	gcc -c test_driver.c -g $(CFLAGS)

randomtestcard1.o: randomtestcard1.c
	gcc -c randomtestcard1.c -g $(CFLAGS)

randomtestcard2.o: randomtestcard2.c
	gcc -c randomtestcard2.c -g $(CFLAGS)

randomtestadventurer.o: randomtestadventurer.c
	gcc -c randomtestadventurer.c -g $(CFLAGS)

testdominion.o: testdominion.c
	gcc -c testdominion.c -g $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittestresults.out: test playdom
	rm -rf unittestresults.out
	./call_tests > unittestresults.out
	echo "GCOV AFTER 1 TEST" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 3 >> results.out
	echo "GCOV AFTER PlAYING A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

almutnaw_unittestresults.out: almutnaw_test playdom
	rm -rf almutnaw_unittestresults.out
	./call_tests > almutnaw_unittestresults.out
	#./call_tests 
	echo "GCOV AFTER 1 TEST" >> almutnaw_unittestresults.out
	gcov almutnaw_dominion.c >> almutnaw_unittestresults.out
	./playdom 3 >> results.out
	echo "GCOV AFTER PlAYING A GAME" >> almutnaw_unittestresults.out
	gcov dominion.c >> almutnaw_unittestresults.out

test: test_driver.o dominion.o rngs.o interface.o
	gcc -o call_tests -g asimpleunittest.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c test_driver.o dominion.o rngs.o interface.o $(CFLAGS)

almutnaw_dominion.o: almutnaw_dominion.c
	gcc -c almutnaw_dominion.c -g  $(CFLAGS)
	

almutnaw_test: test_driver.o almutnaw_dominion.o rngs.o interface.o
	gcc -o call_tests -g asimpleunittest.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c test_driver.o almutnaw_dominion.o rngs.o interface.o $(CFLAGS)

rand: randomtestcard2.o randomtestcard1.o randomtestadventurer.o dominion.o rngs.o interface.o 
	gcc -o test_adventurer -g randomtestadventurer.o dominion.o rngs.o interface.o $(CFLAGS)
	rm -f randomtestadventurer.out
	echo "TEST RESULTS:" > randomtestadventurer.out
	./test_adventurer 42 >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	echo "COVERAGE:" >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	gcov -f dominion.c | grep -A 1 "adventurer" >> randomtestadventurer.out 
	echo "" >> randomtestadventurer.out
	gcc -o test_1 -g randomtestcard1.o dominion.o rngs.o interface.o $(CFLAGS)
	rm -f randomtestcard1.out
	echo "TEST RESULTS:" > randomtestcard1.out
	./test_1 42 >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	echo "COVERAGE:" >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	gcov -f dominion.c | grep -A 1 "council" >> randomtestcard1.out 
	echo "" >> randomtestcard1.out
	gcc -o test_2 -g randomtestcard2.o dominion.o rngs.o interface.o $(CFLAGS)
	rm -f randomtestcard2.out
	echo "TEST RESULTS:" > randomtestcard2.out
	./test_2 42 >> randomtestcard2.out
	echo "" >> randomtestcard2.out
	echo "COVERAGE:" >> randomtestcard2.out
	echo "" >> randomtestcard2.out
	gcov -f dominion.c | grep -A 1 "smithy" >> randomtestcard2.out 
	echo "" >> randomtestcard2.out

testdominion.out: testdominion.o dominion.o rngs.o interface.o 
	gcc -o testdominion -g testdominion.o dominion.o  rngs.o interface.o $(CFLAGS)

adventurer_turantula.o: adventurer_turantula.c
	gcc -c adventurer_turantula.c -g $(CFLAGS)

tarantula.o: tarantula.c
	gcc -c tarantula.c -g $(CFLAGS)

tarantula: adventurer_turantula.o dominion.o rngs.o interface.o
	gcc -o adventurer_turantula -g adventurer_turantula.o dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testdominion.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM

diff_dom:
	./domdiff /nfs/stak/students/b/burnettn/cs362/cs362sp16_burnettn/dominion.c /nfs/stak/students/b/burnettn/cs362/cs362sp16_burnettn/other_dominion/dominion.c 433

diff_dom_20:
	./domdiff20 /nfs/stak/students/b/burnettn/cs362/cs362sp16_burnettn/dominion.c /nfs/stak/students/b/burnettn/cs362/cs362sp16_burnettn/other_dominion/dominion.c
