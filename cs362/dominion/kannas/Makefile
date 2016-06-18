CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g dominion.o rngs.o interface.o $(CFLAGS)

stallcui: dominion.o rngs.o interface.o
	gcc stallcuicardtest1.c dominion.o rngs.o $(CFLAGS) -o st-card1
	gcc stallcuicardtest2.c dominion.o rngs.o $(CFLAGS) -o st-card2
	gcc stallcuicardtest3.c dominion.o rngs.o $(CFLAGS) -o st-card3
	gcc stallcuicardtest4.c dominion.o rngs.o $(CFLAGS) -o st-card4
	gcc stallcuiunittest1.c dominion.o rngs.o $(CFLAGS) -o st-unit1 
	gcc stallcuiunittest2.c dominion.o rngs.o $(CFLAGS) -o st-unit2
	gcc stallcuiunittest3.c dominion.o rngs.o $(CFLAGS) -o st-unit3
	gcc stallcuiunittest4.c dominion.o rngs.o $(CFLAGS) -o st-unit4
	gcc stallcuirand1.c dominion.o rngs.o $(CFLAGS) -o st-rand1
	gcc stallcuirand2.c dominion.o rngs.o interface.o $(CFLAGS) -o st-rand2
	gcc stallcuiranda.c dominion.o rngs.o interface.o $(CFLAGS) -o st-randa


all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randtestadventurer randtestcard1 extrarandomtest randtestcard2 player.exe testInit testInit.exe *.out *.gcov *.gcda *.gcno *.so *.a *.dSYM st-*
