CFLAGS=-std=c11 -g -static

9cc-step2: 9cc-step2.c

test: 9cc
		./test.sh

clean:
		rm -f 9cc *.o *~ tmp*

.PHONY: test clean