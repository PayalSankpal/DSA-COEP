#include"num.c"

//number stack
typedef struct nsnode{
    number* num;
    struct nsnode* next; 
}nsnode;

typedef nsnode* nstack;

void init_nstack(nstack *stk);
int isEmpty(nstack stk);
void push(nstack *stk, number* n);
number* pop(nstack *stk);
number* peek(nstack stk);


//character stack

typedef struct csnode{
    char data;
    struct csnode* next; 
}csnode;

typedef csnode* cstack;

void init_cstack(cstack *stk);
int isEmpty_c(cstack stk);
void push_c(cstack *stk, char n);
char pop_c(cstack *stk);
char peek_c(cstack stk);