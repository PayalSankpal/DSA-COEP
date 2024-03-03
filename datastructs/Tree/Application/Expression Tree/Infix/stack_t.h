#include "tree.h"

typedef struct st_node_t{
    tr_node* data;
    struct st_node_t* next;
}st_node_t;

typedef st_node_t* stack_t;

void init_st_t(stack_t* st);
void push_t(stack_t* st, tr_node* value);
tr_node* pop_t(stack_t* st);
int isEmptyst_t(stack_t st);