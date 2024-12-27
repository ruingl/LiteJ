CC = gcc
CFLAGS = -I./src/include

all: main test

main: src/main.c src/lexer.c
	$(CC) $(CFLAGS) src/main.c src/lexer.c -o main

test: src/tests/lexer_test.c src/lexer.c
	$(CC) $(CFLAGS) src/tests/lexer_test.c src/lexer.c -o test

clean:
	rm -f main test
