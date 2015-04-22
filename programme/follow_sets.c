#include "follow_sets.h"
#include "set.h"

void initializeFollowSets(){
  FOLLOW_SET_START = create_set(_EOF);

  FOLLOW_SET_IDENT_LIST_TYPE = create_set(SEMICOLON);

  FOLLOW_SET_IDENT_LIST = create_set(COLON);

  FOLLOW_SET_TYPE = create_set(SEMICOLON);

  FOLLOW_SET_SIMPLE_TYPE = create_set(SEMICOLON);

  FOLLOW_SET_COMP_STMT = create_set(DOT);
  insert_right(FOLLOW_SET_COMP_STMT, SEMICOLON);
  insert_right(FOLLOW_SET_COMP_STMT, END);
  insert_right(FOLLOW_SET_COMP_STMT, ELSE);

  FOLLOW_SET_STMT_LIST = create_set(END);

  FOLLOW_SET_STATEMENT = create_set(SEMICOLON);
  insert_right(FOLLOW_SET_STATEMENT, END);
  insert_right(FOLLOW_SET_STATEMENT, ELSE);

  FOLLOW_SET_ASSIGN_STMT = create_set(SEMICOLON);
  insert_right(FOLLOW_SET_ASSIGN_STMT, END);
  insert_right(FOLLOW_SET_ASSIGN_STMT, ELSE);

  FOLLOW_SET_ASSIGN_STMT_2 = create_set(SEMICOLON);
  insert_right(FOLLOW_SET_ASSIGN_STMT_2, END);
  insert_right(FOLLOW_SET_ASSIGN_STMT_2, ELSE);

  FOLLOW_SET_IF_STMT = create_set(SEMICOLON);
  insert_right(FOLLOW_SET_IF_STMT, END);
  insert_right(FOLLOW_SET_IF_STMT, ELSE);

  FOLLOW_SET_WHILE_STMT = create_set(SEMICOLON);
  insert_right(FOLLOW_SET_WHILE_STMT, END);
  insert_right(FOLLOW_SET_WHILE_STMT, ELSE);

  FOLLOW_SET_FOR_STMT = create_set(SEMICOLON);
  insert_right(FOLLOW_SET_FOR_STMT, END);
  insert_right(FOLLOW_SET_FOR_STMT, ELSE);

  FOLLOW_SET_TO_PART = create_set(NUMBER);
  insert_right(FOLLOW_SET_TO_PART, FALSE);
  insert_right(FOLLOW_SET_TO_PART, TRUE);
  insert_right(FOLLOW_SET_TO_PART, ID);
  insert_right(FOLLOW_SET_TO_PART, NOT);
  insert_right(FOLLOW_SET_TO_PART, MINUS);
  insert_right(FOLLOW_SET_TO_PART, LEFT_BRACKET);
  insert_right(FOLLOW_SET_TO_PART, STRING);

  FOLLOW_SET_EXPR = create_set(SEMICOLON);
  insert_right(FOLLOW_SET_EXPR, END);
  insert_right(FOLLOW_SET_EXPR, RIGHT_SQUARE_BRACKET);
  insert_right(FOLLOW_SET_EXPR, THEN);
  insert_right(FOLLOW_SET_EXPR, DO);
  insert_right(FOLLOW_SET_EXPR, TO);
  insert_right(FOLLOW_SET_EXPR, DOWNTO);
  insert_right(FOLLOW_SET_EXPR, COMMA);
  insert_right(FOLLOW_SET_EXPR, RIGHT_BRACKET);
  insert_right(FOLLOW_SET_EXPR, ELSE);

  FOLLOW_SET_EXPR_LIST = create_set(RIGHT_BRACKET);

  FOLLOW_SET_SIMPLE_EXPR = create_set(LESS_THAN);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, LESS_EQUAL_THAN);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, GREATER_THAN);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, GREATER_EQUAL_THAN);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, EQUAL);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, UNEQUAL);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, SEMICOLON);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, END);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, RIGHT_SQUARE_BRACKET);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, THEN);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, DO);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, TO);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, DOWNTO);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, COMMA);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, RIGHT_BRACKET);
  insert_right(FOLLOW_SET_SIMPLE_EXPR, ELSE);

  FOLLOW_SET_TERM = create_set(LESS_THAN);
  insert_right(FOLLOW_SET_TERM, LESS_EQUAL_THAN);
  insert_right(FOLLOW_SET_TERM, GREATER_THAN);
  insert_right(FOLLOW_SET_TERM, GREATER_EQUAL_THAN);
  insert_right(FOLLOW_SET_TERM, EQUAL);
  insert_right(FOLLOW_SET_TERM, UNEQUAL);
  insert_right(FOLLOW_SET_TERM, SEMICOLON);
  insert_right(FOLLOW_SET_TERM, END);
  insert_right(FOLLOW_SET_TERM, RIGHT_SQUARE_BRACKET);
  insert_right(FOLLOW_SET_TERM, THEN);
  insert_right(FOLLOW_SET_TERM, DO);
  insert_right(FOLLOW_SET_TERM, TO);
  insert_right(FOLLOW_SET_TERM, DOWNTO);
  insert_right(FOLLOW_SET_TERM, COMMA);
  insert_right(FOLLOW_SET_TERM, RIGHT_BRACKET);
  insert_right(FOLLOW_SET_TERM, ELSE);

  FOLLOW_SET_FACTOR = create_set(STAR);
  insert_right(FOLLOW_SET_FACTOR, SLASH);
  insert_right(FOLLOW_SET_FACTOR, DIV);
  insert_right(FOLLOW_SET_FACTOR, MOD);
  insert_right(FOLLOW_SET_FACTOR, AND);
  insert_right(FOLLOW_SET_FACTOR, PLUS);
  insert_right(FOLLOW_SET_FACTOR, MINUS);
  insert_right(FOLLOW_SET_FACTOR, OR);
  insert_right(FOLLOW_SET_FACTOR, LESS_THAN);
  insert_right(FOLLOW_SET_FACTOR, LESS_EQUAL_THAN);
  insert_right(FOLLOW_SET_FACTOR, GREATER_THAN);
  insert_right(FOLLOW_SET_FACTOR, GREATER_EQUAL_THAN);
  insert_right(FOLLOW_SET_FACTOR, EQUAL);
  insert_right(FOLLOW_SET_FACTOR, UNEQUAL);
  insert_right(FOLLOW_SET_FACTOR, SEMICOLON);
  insert_right(FOLLOW_SET_FACTOR, END);
  insert_right(FOLLOW_SET_FACTOR, RIGHT_SQUARE_BRACKET);
  insert_right(FOLLOW_SET_FACTOR, THEN);
  insert_right(FOLLOW_SET_FACTOR, DO);
  insert_right(FOLLOW_SET_FACTOR, TO);
  insert_right(FOLLOW_SET_FACTOR, DOWNTO);
  insert_right(FOLLOW_SET_FACTOR, COMMA);
  insert_right(FOLLOW_SET_FACTOR, RIGHT_BRACKET);
  insert_right(FOLLOW_SET_FACTOR, ELSE);

  FOLLOW_SET_REL_OP = create_set(NUMBER);
  insert_right(FOLLOW_SET_REL_OP, FALSE);
  insert_right(FOLLOW_SET_REL_OP, TRUE);
  insert_right(FOLLOW_SET_REL_OP, ID);
  insert_right(FOLLOW_SET_REL_OP, NOT);
  insert_right(FOLLOW_SET_REL_OP, MINUS);
  insert_right(FOLLOW_SET_REL_OP, LEFT_BRACKET);
  insert_right(FOLLOW_SET_REL_OP, STRING);

  FOLLOW_SET_ADD_OP = create_set(NUMBER);
  insert_right(FOLLOW_SET_ADD_OP, FALSE);
  insert_right(FOLLOW_SET_ADD_OP, TRUE);
  insert_right(FOLLOW_SET_ADD_OP, ID);
  insert_right(FOLLOW_SET_ADD_OP, NOT);
  insert_right(FOLLOW_SET_ADD_OP, MINUS);
  insert_right(FOLLOW_SET_ADD_OP, LEFT_BRACKET);
  insert_right(FOLLOW_SET_ADD_OP, STRING);

  FOLLOW_SET_MUL_OP = create_set(NUMBER);
  insert_right(FOLLOW_SET_MUL_OP, FALSE);
  insert_right(FOLLOW_SET_MUL_OP, TRUE);
  insert_right(FOLLOW_SET_MUL_OP, ID);
  insert_right(FOLLOW_SET_MUL_OP, NOT);
  insert_right(FOLLOW_SET_MUL_OP, MINUS);
  insert_right(FOLLOW_SET_MUL_OP, LEFT_BRACKET);
  insert_right(FOLLOW_SET_MUL_OP, STRING);
}
