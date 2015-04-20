#include "parser.h"
#include "lex.yy.c"
#include "tokens.h"

enum Tokens token;

int main() {
  token = yylex();
  match(PROGRAM);
  program();
  printf("There are no lexical and syntactical errors\n");
  return 0;
}

void syntacticError(char *message){
  fprintf(stderr, "Syntactic error (line: %d, token: %s): \"%s\"\n", yylineno, yytext, message); 
  exit(1);
}

/* For terminals */
void match(enum Tokens expectedToken){
  if(token == expectedToken){
    // Get next token
    token = yylex();
  }
  else{
    char message[40];
    sprintf(message, "Expected token %s", stringFromToken(expectedToken));
    syntacticError(message);
  }
}

/* Non-terminals */
void program(){
  match(ID);
  match(SEMICOLON);
  varDec();
  compStmt();
  match(DOT);
}

void varDec(){
  if(token == VAR){
    match(VAR);
    varDecList();
  }
}

void varDecList(){
  identListType();
  match(SEMICOLON);
  varDecList2();
}

void varDecList2(){
  while(token == ID){
    identListType();
    match(SEMICOLON);
  }
}

void identListType(){
  identList();
  match(COLON);
  type();
}

void identList(){
  match(ID);
  identList2();
}

void identList2(){
  while(token == COMMA){
    match(COMMA);
    match(ID);
  }
}

void type(){
  if(token == ARRAY){
    match(ARRAY);
    match(LEFT_SQUARE_BRACKET);
    match(NUMBER);
    match(DOT_DOT);
    match(NUMBER);
    match(RIGHT_SQUARE_BRACKET);
    match(OF);
    simpleType();
  }
  else{
    simpleType();
  }
}

void simpleType(){
  switch(token){
  case INTEGER: match(INTEGER); break;
  case REAL: match(REAL); break;
  case BOOLEAN: match(BOOLEAN); break;
  default: syntacticError("Expected token \"INTEGER\", \"REAL\" OR \"BOOLEAN\""); break;
  }
}

void compStmt(){
  match(_BEGIN);
  stmtList();
  match(END);
}

void stmtList(){
  statement();
  stmtList2();
}

void stmtList2(){
  while(token == SEMICOLON){
    match(SEMICOLON);
    statement();
  }
}

void statement(){
  switch(token){
  case ID: assignStmt(); break;
  case _BEGIN: compStmt(); break;
  case IF: ifStmt(); break;
  case WHILE: whileStmt(); break;
  case FOR: forStmt(); break;
  case READ: 
    match(READ); 
    match(LEFT_BRACKET);
    exprList();
    match(RIGHT_BRACKET);
    break;
  case WRITE:
    match(WRITE);
    match(LEFT_BRACKET);
    exprList();
    match(RIGHT_BRACKET);
    break;
  default: syntacticError("Expected token \"ID\", \"IF\", \"WHILE\", \"FOR\", \"READ\" or \"WRITE\""); break;
  }
}

void assignStmt(){
  match(ID);
  assignStmt2();
}

void assignStmt2(){
  switch(token){
  case ASSIGNMENT:
    match(ASSIGNMENT);
    expr();
    break;
  case LEFT_SQUARE_BRACKET:
    match(LEFT_SQUARE_BRACKET);
    expr();
    match(RIGHT_SQUARE_BRACKET);
    match(ASSIGNMENT);
    expr();
    break;
  default: syntacticError("Expected token \"ASSIGNMENT\" or \"LEFT_SQUARE_BRACKET\""); break;
  }
}

void ifStmt(){
  match(IF);
  expr();
  match(THEN);
  statement();
  if(token == ELSE){
    elsePart();
  }
}

void elsePart(){
  match(ELSE);
  statement();
}

void whileStmt(){
  match(WHILE);
  expr();
  match(DO);
  statement();
}

void forStmt(){
  match(FOR);
  match(ID);
  match(ASSIGNMENT);
  expr();
  toPart();
  expr();
  match(DO);
  statement();
}

void toPart(){
  switch(token){
  case TO: match(TO); break;
  case DOWNTO: match(DOWNTO); break;
  default: syntacticError("Expected token \"TO\" or \"DOWNTO\""); break;
  }
}

void expr(){
  simpleExpr();
  expr2();
}

void expr2(){
  switch(token){
  case LESS_THAN:
  case LESS_EQUAL_THAN:
  case GREATER_THAN:
  case GREATER_EQUAL_THAN:
  case EQUAL:
  case UNEQUAL:
    relOp();
    simpleExpr();
    break;
  }
}

void exprList(){
  expr();
  exprList2();
}

void exprList2(){
  while(token == COMMA){
    match(COMMA);
    expr();
  }
}

void simpleExpr(){
  term();
  simpleExpr2();
}

void simpleExpr2(){
  while(token == PLUS || token == MINUS || token == OR){
    addOp();
    term();
  }
}

void term(){
  factor();
  term2();
}

void term2(){
  while(token == STAR || token == SLASH || token == DIV || token == MOD || token == AND){
    mulOp();
    factor();
  }
}

void factor(){
  switch(token){
  case NUMBER: match(NUMBER); break;
  case FALSE: match(FALSE); break;
  case TRUE: match(TRUE); break;
  case ID:
    match(ID);
    factorIdent();
    break;
  case NOT:
    match(NOT);
    factor();
    break;
  case MINUS:
    match(MINUS);
    factor();
    break;
  case LEFT_BRACKET:
    match(LEFT_BRACKET);
    expr();
    match(RIGHT_BRACKET);
    break;
  case STRING:
    match(STRING);
    break;
  default: syntacticError("Expected token \"NUMBER\", \"FALSE\", \"TRUE\", \"ID\", \"NOT\", \"MINUS\", \"LEFT_BRACKET\" or \"STRING\""); break;
  }
}

void factorIdent(){
  if(token == LEFT_SQUARE_BRACKET){
    match(LEFT_SQUARE_BRACKET);
    expr();
    match(RIGHT_SQUARE_BRACKET);
  }
}

void relOp(){
  switch(token){
  case LESS_THAN: match(LESS_THAN); break;
  case LESS_EQUAL_THAN: match(LESS_EQUAL_THAN); break;
  case GREATER_THAN: match(GREATER_THAN); break;
  case GREATER_EQUAL_THAN: match(GREATER_EQUAL_THAN); break;
  case EQUAL: match(EQUAL); break;
  case UNEQUAL: match(UNEQUAL); break;
  default: syntacticError("Expected token \"LESS_THAN\", \"LESS_EQUAL_THAN\", \"GREATER_THAN\", \"GREATER_EQUAL_THAN\", \"EQUAL\" or \"UNEQUAL\""); break;
  }
}

void addOp(){
  switch(token){
  case PLUS: match(PLUS); break;
  case MINUS: match(MINUS); break;
  case OR: match(OR); break;
  default: syntacticError("Expected token \"PLUS\", \"MINUS\" or \"OR\""); 
  }
}

void mulOp(){
  switch(token){
  case STAR: match(STAR); break;
  case SLASH: match(SLASH); break;
  case DIV: match(DIV); break;
  case MOD: match(MOD); break;
  case AND: match(AND); break;
  default: syntacticError("Expected token \"STAR\", \"SLASH\", \"DIV\", \"MOD\" or \"AND\""); 
  }
}
