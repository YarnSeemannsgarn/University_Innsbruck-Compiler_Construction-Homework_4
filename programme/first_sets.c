#include "first_sets.h"
#include "set.h"
#include <stdio.h>

void initializeFirstSets(){
  FIRST_SET_START = create_set(PROGRAM);

  FIRST_SET_IDENT_LIST_TYPE = create_set(ID);

  FIRST_SET_IDENT_LIST = create_set(ID);

  FIRST_SET_TYPE = create_set(INTEGER);
  insert_right(FIRST_SET_TYPE, REAL);
  insert_right(FIRST_SET_TYPE, BOOLEAN);
  insert_right(FIRST_SET_TYPE, ARRAY);
  
  
  FIRST_SET_SIMPLE_TYPE = create_set(INTEGER);
  insert_right(FIRST_SET_SIMPLE_TYPE, REAL);
  insert_right(FIRST_SET_SIMPLE_TYPE, BOOLEAN);

  FIRST_SET_COMP_STMT = create_set(_BEGIN);

  FIRST_SET_STMT_LIST = create_set(ID);
  insert_right(FIRST_SET_STMT_LIST, _BEGIN);
  insert_right(FIRST_SET_STMT_LIST, IF);
  insert_right(FIRST_SET_STMT_LIST, WHILE);
  insert_right(FIRST_SET_STMT_LIST, FOR);
  insert_right(FIRST_SET_STMT_LIST, READ);
  insert_right(FIRST_SET_STMT_LIST, WRITE);

  FIRST_SET_STATEMENT = create_set(ID);
  insert_right(FIRST_SET_STATEMENT, _BEGIN);
  insert_right(FIRST_SET_STATEMENT, IF);
  insert_right(FIRST_SET_STATEMENT, WHILE);
  insert_right(FIRST_SET_STATEMENT, FOR);
  insert_right(FIRST_SET_STATEMENT, READ);
  insert_right(FIRST_SET_STATEMENT, WRITE);

  FIRST_SET_ASSIGN_STMT = create_set(ID);

  FIRST_SET_ASSIGNT_STMT_2 = create_set(ASSIGNMENT);
  insert_right(FIRST_SET_ASSIGNT_STMT_2, LEFT_SQUARE_BRACKET);

  FIRST_SET_IF_STMT = create_set(IF);

  FIRST_SET_WHILE_STMT = create_set(WHILE);

  FIRST_SET_FOR_STMT = create_set(FOR);

  FIRST_SET_TO_PART = create_set(TO);
  insert_right(FIRST_SET_TO_PART, DOWNTO);

  FIRST_SET_EXPR = create_set(NUMBER);
  insert_right(FIRST_SET_EXPR, FALSE);
  insert_right(FIRST_SET_EXPR, TRUE);
  insert_right(FIRST_SET_EXPR, ID);
  insert_right(FIRST_SET_EXPR, NOT);
  insert_right(FIRST_SET_EXPR, MINUS);
  insert_right(FIRST_SET_EXPR, RIGHT_BRACKET);
  insert_right(FIRST_SET_EXPR, STRING);

  FIRST_SET_EXPR_LIST = create_set(NUMBER);
  insert_right(FIRST_SET_EXPR_LIST, FALSE);
  insert_right(FIRST_SET_EXPR_LIST, TRUE);
  insert_right(FIRST_SET_EXPR_LIST, ID);
  insert_right(FIRST_SET_EXPR_LIST, NOT);
  insert_right(FIRST_SET_EXPR_LIST, MINUS);
  insert_right(FIRST_SET_EXPR_LIST, RIGHT_BRACKET);
  insert_right(FIRST_SET_EXPR_LIST, STRING);

  FIRST_SET_SIMPLE_EXPR = create_set(NUMBER);
  insert_right(FIRST_SET_SIMPLE_EXPR, FALSE);
  insert_right(FIRST_SET_SIMPLE_EXPR, TRUE);
  insert_right(FIRST_SET_SIMPLE_EXPR, ID);
  insert_right(FIRST_SET_SIMPLE_EXPR, NOT);
  insert_right(FIRST_SET_SIMPLE_EXPR, MINUS);
  insert_right(FIRST_SET_SIMPLE_EXPR, RIGHT_BRACKET);
  insert_right(FIRST_SET_SIMPLE_EXPR, STRING);

  FIRST_SET_TERM = create_set(NUMBER);
  insert_right(FIRST_SET_TERM, FALSE);
  insert_right(FIRST_SET_TERM, TRUE);
  insert_right(FIRST_SET_TERM, ID);
  insert_right(FIRST_SET_TERM, NOT);
  insert_right(FIRST_SET_TERM, MINUS);
  insert_right(FIRST_SET_TERM, RIGHT_BRACKET);
  insert_right(FIRST_SET_TERM, STRING);

  FIRST_SET_FACTOR = create_set(NUMBER);
  insert_right(FIRST_SET_FACTOR, FALSE);
  insert_right(FIRST_SET_FACTOR, TRUE);
  insert_right(FIRST_SET_FACTOR, ID);
  insert_right(FIRST_SET_FACTOR, NOT);
  insert_right(FIRST_SET_FACTOR, MINUS);
  insert_right(FIRST_SET_FACTOR, LEFT_BRACKET);
  insert_right(FIRST_SET_FACTOR, STRING);

  FIRST_SET_REL_OP = create_set(LESS_THAN);
  insert_right(FIRST_SET_REL_OP, LESS_EQUAL_THAN);
  insert_right(FIRST_SET_REL_OP, GREATER_THAN);
  insert_right(FIRST_SET_REL_OP, GREATER_EQUAL_THAN);
  insert_right(FIRST_SET_REL_OP, EQUAL);
  insert_right(FIRST_SET_REL_OP, UNEQUAL);

  FIRST_SET_ADD_OP = create_set(PLUS);
  insert_right(FIRST_SET_ADD_OP, MINUS);
  insert_right(FIRST_SET_ADD_OP, OR);

  FIRST_SET_MUL_OP = create_set(STAR);
  insert_right(FIRST_SET_MUL_OP, SLASH);
  insert_right(FIRST_SET_MUL_OP, DIV);
  insert_right(FIRST_SET_MUL_OP, MOD);
  insert_right(FIRST_SET_MUL_OP, AND);
}
