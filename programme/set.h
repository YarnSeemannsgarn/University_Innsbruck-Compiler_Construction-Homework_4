#ifndef SET_H
#define SET_H

#include "tokens.h"

struct set_node {
  enum Tokens terminal;
  struct set_node *next;
};

typedef struct set_node* node;

node create_set(enum Tokens terminal);
node insert_right(node set, enum Tokens terminal);
node search_for(node set, enum Tokens terminal);

#endif
