typedef struct st_node{
    char data;
    struct st_node* next;
}st_node;

typedef st_node* stack;

void init_st(stack* st);
void push(stack* st, char value);
char pop(stack* st);
int isEmptyst(stack st);