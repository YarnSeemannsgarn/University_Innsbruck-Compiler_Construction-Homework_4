#ifndef FOLLOW_SETS_H
#define FOLLOW_SETS_H

#include "tokens.h"
#include "set.h"

node FOLLOW_SET_START;
FOLLOW_SET_START = insert_right(FOLLOW_SET_START, _EOF);

node FOLLOW_SET_IDENT_LIST_TYPE;
FOLLOW_SET_IDENT_LIST_TYPE = insert_right(FOLLOW_SET_IDENT_LIST_TYPE, SEMICOLON);

node FOLLOW_SET_IDENT_LIST;
FOLLOW_SET_IDENT_LIST = insert_right(FOLLOW_SET_IDENT_LIST, COLON);

node FOLLOW_SET_TYPE;
FOLLOW_SET_TYPE = insert_right(FOLLOW_SET_TYPE, SEMICOLON);

node FOLLOW_SET_SIMPLE_TYPE;
FOLLOW_SET_SIMPLE_TYPE = insert_right(FOLLOW_SET_SIMPLE_TYPE, SEMICOLON);

node FOLLOW_SET_COMP_STMT;
FOLLOW_SET_COMP_STMT = insert_right(FOLLOW_SET_COMP_STMT, DOT);
FOLLOW_SET_COMP_STMT = insert_right(FOLLOW_SET_COMP_STMT, SEMICOLON);
FOLLOW_SET_COMP_STMT = insert_right(FOLLOW_SET_COMP_STMT, END);
FOLLOW_SET_COMP_STMT = insert_right(FOLLOW_SET_COMP_STMT, ELSE);

node FOLLOW_SET_STMT_LIST;
FOLLOW_SET_STMT_LIST = insert_right(FOLLOW_SET_STMT_LIST, END);

node FOLLOW_SET_STATEMENT;
FOLLOW_SET_STATEMENT = insert_right(FOLLOW_SET_STATEMENT, SEMICOLON);
FOLLOW_SET_STATEMENT = insert_right(FOLLOW_SET_STATEMENT, END);
FOLLOW_SET_STATEMENT = insert_right(FOLLOW_SET_STATEMENT, ELSE);

node FOLLOW_SET_ASSIGN_STMT;
FOLLOW_SET_ASSIGN_STMT = insert_right(FOLLOW_SET_ASSIGN_STMT, SEMICOLON);
FOLLOW_SET_ASSIGN_STMT = insert_right(FOLLOW_SET_ASSIGN_STMT, END);
FOLLOW_SET_ASSIGN_STMT = insert_right(FOLLOW_SET_ASSIGN_STMT, ELSE);

node FOLLOW_SET_ASSIGN_STMT_2;
FOLLOW_SET_ASSIGN_STMT_2 = insert_right(FOLLOW_SET_ASSIGN_STMT_2, SEMICOLON);
FOLLOW_SET_ASSIGN_STMT_2 = insert_right(FOLLOW_SET_ASSIGN_STMT_2, END);
FOLLOW_SET_ASSIGN_STMT_2 = insert_right(FOLLOW_SET_ASSIGN_STMT_2, ELSE);

node FOLLOW_SET_IF_STMT;
FOLLOW_SET_IF_STMT = insert_right(FOLLOW_SET_IF_STMT, SEMICOLON);
FOLLOW_SET_IF_STMT = insert_right(FOLLOW_SET_IF_STMT, END);
FOLLOW_SET_IF_STMT = insert_right(FOLLOW_SET_IF_STMT, ELSE);

node FOLLOW_SET_WHILE_STMT;
FOLLOW_SET_WHILE_STMT = insert_right(FOLLOW_SET_WHILE_STMT, SEMICOLON);
FOLLOW_SET_WHILE_STMT = insert_right(FOLLOW_SET_WHILE_STMT, END);
FOLLOW_SET_WHILE_STMT = insert_right(FOLLOW_SET_WHILE_STMT, ELSE);

node FOLLOW_SET_FOR_STMT;
FOLLOW_SET_FOR_STMT = insert_right(FOLLOW_SET_FOR_STMT, SEMICOLON);
FOLLOW_SET_FOR_STMT = insert_right(FOLLOW_SET_FOR_STMT, END);
FOLLOW_SET_FOR_STMT = insert_right(FOLLOW_SET_FOR_STMT, ELSE);

node FOLLOW_SET_TO_PART;
FOLLOW_SET_TO_PART = insert_right(FOLLOW_SET_TO_PART, NUMBER);
FOLLOW_SET_TO_PART = insert_right(FOLLOW_SET_TO_PART, FALSE);
FOLLOW_SET_TO_PART = insert_right(FOLLOW_SET_TO_PART, TRUE);
FOLLOW_SET_TO_PART = insert_right(FOLLOW_SET_TO_PART, ID);
FOLLOW_SET_TO_PART = insert_right(FOLLOW_SET_TO_PART, NOT);
FOLLOW_SET_TO_PART = insert_right(FOLLOW_SET_TO_PART, MINUS);
FOLLOW_SET_TO_PART = insert_right(FOLLOW_SET_TO_PART, LEFT_BRACKET);
FOLLOW_SET_TO_PART = insert_right(FOLLOW_SET_TO_PART, STRING);

node FOLLOW_SET_EXPR;
FOLLOW_SET_EXPR = insert_right(FOLLOW_SET_EXPR, SEMICOLON);
FOLLOW_SET_EXPR = insert_right(FOLLOW_SET_EXPR, END);
FOLLOW_SET_EXPR = insert_right(FOLLOW_SET_EXPR, RIGHT_SQUARE_BRACKET);
FOLLOW_SET_EXPR = insert_right(FOLLOW_SET_EXPR, THEN);
FOLLOW_SET_EXPR = insert_right(FOLLOW_SET_EXPR, DO);
FOLLOW_SET_EXPR = insert_right(FOLLOW_SET_EXPR, TO);
FOLLOW_SET_EXPR = insert_right(FOLLOW_SET_EXPR, DOWNTO);
FOLLOW_SET_EXPR = insert_right(FOLLOW_SET_EXPR, COMMA);
FOLLOW_SET_EXPR = insert_right(FOLLOW_SET_EXPR, RIGHT_BRACKET);
FOLLOW_SET_EXPR = insert_right(FOLLOW_SET_EXPR, ELSE);

node FOLLOW_SET_EXPR_LIST;
FOLLOW_SET_EXPR_LIST = insert_right(FOLLOW_SET_EXPR_LIST, RIGHT_BRACKET);

node FOLLOW_SET_SIMPLE_EXPR;
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, LESS_THAN);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, LESS_EQUAL_THAN);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, GREATER_THAN);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, GREATER_EQUAL_THAN);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, EQUAL);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, UNEQUAL);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, SEMICOLON);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, END);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, RIGHT_SQUARE_BRACKET);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, THEN);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, DO);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, TO);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, DOWNTO);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, COMMA);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, RIGHT_BRACKET);
FOLLOW_SET_SIMPLE_EXPR = insert_right(FOLLOW_SET_SIMPLE_EXPR, ELSE);

node FOLLOW_SET_TERM;
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, LESS_THAN);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, LESS_EQUAL_THAN);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, GREATER_THAN);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, GREATER_EQUAL_THAN);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, EQUAL);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, UNEQUAL);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, SEMICOLON);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, END);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, RIGHT_SQUARE_BRACKET);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, THEN);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, DO);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, TO);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, DOWNTO);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, COMMA);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, RIGHT_BRACKET);
FOLLOW_SET_TERM = insert_right(FOLLOW_SET_TERM, ELSE);

node FOLLOW_SET_FACTOR;
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, STAR);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, SLASH);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, DIV);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, MOD);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, AND);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, PLUS);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, MINUS);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, OR);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, LESS_THAN);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, LESS_EQUAL_THAN);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, GREATER_THAN);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, GREATER_EQUAL_THAN);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, EQUAL);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, UNEQUAL);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, SEMICOLON);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, END);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, RIGHT_SQUARE_BRACKET);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, THEN);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, DO);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, TO);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, DOWNTO);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, COMMA);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, RIGHT_BRACKET);
FOLLOW_SET_FACTOR = insert_right(FOLLOW_SET_FACTOR, ELSE);

node FOLLOW_SET_REL_OP;
FOLLOW_SET_REL_OP = insert_right(FOLLOW_SET_REL_OP, NUMBER);
FOLLOW_SET_REL_OP = insert_right(FOLLOW_SET_REL_OP, FALSE);
FOLLOW_SET_REL_OP = insert_right(FOLLOW_SET_REL_OP, TRUE);
FOLLOW_SET_REL_OP = insert_right(FOLLOW_SET_REL_OP, ID);
FOLLOW_SET_REL_OP = insert_right(FOLLOW_SET_REL_OP, NOT);
FOLLOW_SET_REL_OP = insert_right(FOLLOW_SET_REL_OP, MINUS);
FOLLOW_SET_REL_OP = insert_right(FOLLOW_SET_REL_OP, LEFT_BRACKET);
FOLLOW_SET_REL_OP = insert_right(FOLLOW_SET_REL_OP, STRING);

node FOLLOW_SET_ADD_OP;
FOLLOW_SET_ADD_OP = insert_right(FOLLOW_SET_ADD_OP, NUMBER);
FOLLOW_SET_ADD_OP = insert_right(FOLLOW_SET_ADD_OP, FALSE);
FOLLOW_SET_ADD_OP = insert_right(FOLLOW_SET_ADD_OP, TRUE);
FOLLOW_SET_ADD_OP = insert_right(FOLLOW_SET_ADD_OP, ID);
FOLLOW_SET_ADD_OP = insert_right(FOLLOW_SET_ADD_OP, NOT);
FOLLOW_SET_ADD_OP = insert_right(FOLLOW_SET_ADD_OP, MINUS);
FOLLOW_SET_ADD_OP = insert_right(FOLLOW_SET_ADD_OP, LEFT_BRACKET);
FOLLOW_SET_ADD_OP = insert_right(FOLLOW_SET_ADD_OP, STRING);

node FOLLOW_SET_MUL_OP;
FOLLOW_SET_MUL_OP = insert_right(FOLLOW_SET_MUL_OP, NUMBER);
FOLLOW_SET_MUL_OP = insert_right(FOLLOW_SET_MUL_OP, FALSE);
FOLLOW_SET_MUL_OP = insert_right(FOLLOW_SET_MUL_OP, TRUE);
FOLLOW_SET_MUL_OP = insert_right(FOLLOW_SET_MUL_OP, ID);
FOLLOW_SET_MUL_OP = insert_right(FOLLOW_SET_MUL_OP, NOT);
FOLLOW_SET_MUL_OP = insert_right(FOLLOW_SET_MUL_OP, MINUS);
FOLLOW_SET_MUL_OP = insert_right(FOLLOW_SET_MUL_OP, LEFT_BRACKET);
FOLLOW_SET_MUL_OP = insert_right(FOLLOW_SET_MUL_OP, STRING);

#endif
