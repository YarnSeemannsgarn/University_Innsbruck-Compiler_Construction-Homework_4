LEX = flex
CC = gcc

OBJS = set.o parser.o first_sets.o follow_sets.o

all: parser

parser: ${OBJS}
	$(CC) -o $@ ${OBJS}

lex.yy.c: scanner.l tokens.h 
	$(LEX) scanner.l

set.o: set.h tokens.h
	$(CC) -c set.c

first_sets.o: first_sets.h set.h
	$(CC) -c first_sets.c

follow_sets.o: follow_sets.h set.h
	$(CC) -c follow_sets.c

parser.o: parser.c lex.yy.c tokens.h set.h first_sets.h follow_sets.h
	$(CC) -c parser.c

clean:
	rm -f lex.yy.c parser *.o
