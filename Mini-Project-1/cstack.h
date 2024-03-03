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