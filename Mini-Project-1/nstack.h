
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