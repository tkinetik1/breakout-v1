#
# Makefile
#
# Computer Science 50
# Problem Set 4
#
#all: cursor cursor-test paddle-test breakout

all:  bricks-test-2

cursor: cursor.c Makefile
	clang -ggdb3 -Ispl/include -O0 -std=c99 -Wall -Werror -Wno-unused-variable -o cursor cursor.c -Lspl/lib -lcs -lm

cursor-test: cursor-test.c Makefile
	clang -ggdb3 -Ispl/include -O0 -std=c99 -Wall -Werror -Wno-unused-variable -o cursor-test cursor-test.c -Lspl/lib -lcs -lm

bricks-test: bricks-test.c Makefile
	clang -ggdb3 -Ispl/include -O0 -std=c99 -Wall -Werror -Wno-unused-variable -o bricks-test bricks-test.c -Lspl/lib -lcs -lm

bricks-test-2: bricks-test-2.c Makefile
	clang -ggdb3 -Ispl/include -O0 -std=c99 -Wall -Werror -Wno-unused-variable -o bricks-test-2 bricks-test-2.c -Lspl/lib -lcs -lm


breakout: breakout.c Makefile
	clang -ggdb3 -Ispl/include -O0 -std=c99 -Wall -Werror -Wno-unused-variable -o breakout breakout.c -Lspl/lib -lcs -lm
clean:
	rm -f *.o core breakout
