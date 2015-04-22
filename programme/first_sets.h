#ifndef FIRST_SETS_H
#define FIRST_SETS_H

#include "tokens.h"
#include "set.h"

void initializeFirstSets();

// No first sets with epsilon, because then first set validation does not matter
node FIRST_SET_START;
node FIRST_SET_IDENT_LIST_TYPE;
node FIRST_SET_IDENT_LIST;
node FIRST_SET_TYPE;
node FIRST_SET_SIMPLE_TYPE;
node FIRST_SET_COMP_STMT;
node FIRST_SET_STMT_LIST;
node FIRST_SET_STATEMENT;
node FIRST_SET_ASSIGN_STMT;
node FIRST_SET_ASSIGNT_STMT_2;
node FIRST_SET_IF_STMT;
node FIRST_SET_WHILE_STMT;
node FIRST_SET_FOR_STMT;
node FIRST_SET_TO_PART;
node FIRST_SET_EXPR;
node FIRST_SET_EXPR_LIST;
node FIRST_SET_SIMPLE_EXPR;
node FIRST_SET_TERM;
node FIRST_SET_FACTOR;
node FIRST_SET_REL_OP;
node FIRST_SET_ADD_OP;
node FIRST_SET_MUL_OP;

#endif
