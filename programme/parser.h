#ifndef PARSER_H
#define PARSER_H

#include "tokens.h"

int main();
void syntacticError(char *message);

void match(enum Tokens expectedToken);

/* Non-terminals */
void program();
void varDec();
void varDecList();
void varDecList2();
void identListType();
void identList();
void identList2();
void type();
void simpleType();
void compStmt();
void stmtList();
void stmtList2();
void statement();
void assignStmt();
void assignStmt2();
void ifStmt();
void elsePart();
void whileStmt();
void forStmt();
void toPart();
void expr();
void expr2();
void exprList();
void exprList2();
void simpleExpr();
void simpleExpr2();
void term();
void term2();
void factor();
void factorIdent();
void relOp();
void addOp();
void mulOp();

#endif
