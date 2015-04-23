#include "parser.h"
#include "lex.yy.c"
#include "tokens.h"
#include "set.h"
#include "first_sets.h"
#include "follow_sets.h"

enum Tokens token;

int main() {
  initializeFirstSets();
  initializeFollowSets();

  token = yylex();
  checkInput(FIRST_SET_START, FOLLOW_SET_START, "START");
  match(PROGRAM);
  program();
  return 0;
}

void checkInput(node firstSet, node followSet, char *setName){
  // Task 2: Error detection
  if(search_for(firstSet, token) == NULL){
    char message[100];
    sprintf(message, "Token not in first set of %s. Parser scans until it reaches token of first or follow set", setName);
    syntacticError(message);
    
    // Task 3: Error recovery
    scanTo(firstSet, followSet);
  }
}

void scanTo(node firstSet, node followSet){
  while(search_for(firstSet, token) == NULL && search_for(followSet, token) == NULL && token != _EOF){
    token = yylex();
  }
  if(search_for(firstSet, token) != NULL){
    printf("Found token in first set (line: %d, token: \"%s\")\n", yylineno, yytext); 
  }
  else if(search_for(followSet, token) != NULL){
    printf("Found token in follow set (line: %d, token: \"%s\")\n", yylineno, yytext); 
  }
}

void syntacticError(char *message){
  fprintf(stderr, "Syntactic error (line: %d, token: \"%s\"): %s\n", yylineno, yytext, message);
}

/* For terminals */
void match(enum Tokens expectedToken){
  if(token == expectedToken){
    // Get next token
    token = yylex();
  }
  else{
    char message[40];
    sprintf(message, "Expected token \"%s\"", stringFromToken(expectedToken));
    syntacticError(message);
    exit(1);
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
  checkInput(FIRST_SET_IDENT_LIST_TYPE, FOLLOW_SET_IDENT_LIST_TYPE, "IDENT_LIST_TYPE");
  identList();
  match(COLON);
  type();
}

void identList(){
  checkInput(FIRST_SET_IDENT_LIST, FOLLOW_SET_IDENT_LIST, "IDENT_LIST");
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
  checkInput(FIRST_SET_TYPE, FOLLOW_SET_TYPE, "TYPE");
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
  checkInput(FIRST_SET_SIMPLE_TYPE, FOLLOW_SET_SIMPLE_TYPE, "SIMPLE_TYPE");
  switch(token){
  case INTEGER: match(INTEGER); break;
  case REAL: match(REAL); break;
  case BOOLEAN: match(BOOLEAN); break;
  default: syntacticError("Expected token \"INTEGER\", \"REAL\" OR \"BOOLEAN\""); break;
  }
}

void compStmt(){
  checkInput(FIRST_SET_COMP_STMT, FOLLOW_SET_COMP_STMT, "COMP_STMT");
  match(_BEGIN);
  stmtList();
  match(END);
}

void stmtList(){
  checkInput(FIRST_SET_STMT_LIST, FOLLOW_SET_STMT_LIST, "STMT_LIST");
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
  checkInput(FIRST_SET_STATEMENT, FOLLOW_SET_STATEMENT, "STATEMENT");
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
  checkInput(FIRST_SET_ASSIGN_STMT, FOLLOW_SET_ASSIGN_STMT, "ASSIGN_STMT");
  match(ID);
  assignStmt2();
}

void assignStmt2(){
  checkInput(FIRST_SET_ASSIGNT_STMT_2, FOLLOW_SET_ASSIGN_STMT_2, "ASSIGN_STMT_2");
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
  checkInput(FIRST_SET_IF_STMT, FOLLOW_SET_IF_STMT, "IF_STMT");
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
  checkInput(FIRST_SET_WHILE_STMT, FOLLOW_SET_WHILE_STMT, "WHILE_STMT");
  match(WHILE);
  expr();
  match(DO);
  statement();
}

void forStmt(){
  checkInput(FIRST_SET_FOR_STMT, FOLLOW_SET_FOR_STMT, "FOR_STMT");
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
  checkInput(FIRST_SET_TO_PART, FOLLOW_SET_TO_PART, "TO_PART");
  switch(token){
  case TO: match(TO); break;
  case DOWNTO: match(DOWNTO); break;
  default: syntacticError("Expected token \"TO\" or \"DOWNTO\""); break;
  }
}

void expr(){
  checkInput(FIRST_SET_EXPR, FOLLOW_SET_EXPR, "EXPR");
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
  checkInput(FIRST_SET_EXPR_LIST, FOLLOW_SET_EXPR_LIST, "EXPR_LIST");
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
  checkInput(FIRST_SET_SIMPLE_EXPR, FOLLOW_SET_SIMPLE_EXPR, "SIMPLE_EXPR");
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
  checkInput(FIRST_SET_TERM, FOLLOW_SET_TERM, "TERM");
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
  checkInput(FIRST_SET_FACTOR, FOLLOW_SET_FACTOR, "FACTOR");
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
  checkInput(FIRST_SET_REL_OP, FOLLOW_SET_REL_OP, "REL_OP");
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
  checkInput(FIRST_SET_ADD_OP, FOLLOW_SET_ADD_OP, "ADD_OP");
  switch(token){
  case PLUS: match(PLUS); break;
  case MINUS: match(MINUS); break;
  case OR: match(OR); break;
  default: syntacticError("Expected token \"PLUS\", \"MINUS\" or \"OR\""); 
  }
}

void mulOp(){
  checkInput(FIRST_SET_MUL_OP, FOLLOW_SET_MUL_OP, "MUL_OP");
  switch(token){
  case STAR: match(STAR); break;
  case SLASH: match(SLASH); break;
  case DIV: match(DIV); break;
  case MOD: match(MOD); break;
  case AND: match(AND); break;
  default: syntacticError("Expected token \"STAR\", \"SLASH\", \"DIV\", \"MOD\" or \"AND\""); 
  }
}
