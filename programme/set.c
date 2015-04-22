/* Taken from http://perlgeek.de/de/artikel/einfach-verkettete-listen */
#include "set.h"
#inckude "tokens.h"

node insert_right(node set, enum Tokens terminal){
  node new_node = (node) malloc(sizeof(struct set_node));
  new_node->terminal = terminal;
  new_node->next = set->next;
  set->next     = new_node;
  return new_node;
}

node search_for(node set, enum Tokens terminal) {
  while (set != NULL) {
    if (set->terminal == terminal)
      return set;
    set = set->next;
  }
  return NULL;
}
