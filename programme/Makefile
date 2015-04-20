LEX = flex
CC = gcc

all: parser

lex.yy.c: scanner.l tokens.h
	$(LEX) scanner.l

parser: parser.c lex.yy.c tokens.h
	$(CC) -o $@ parser.c $(CFLAGS)

clean:
	rm -f lex.yy.c parser
