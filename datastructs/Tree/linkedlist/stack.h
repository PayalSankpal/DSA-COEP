

typedef struct snode{
    node* data;
    struct snode* next; 
}snode;

typedef snode* stack;

void init_stack(stack *stk);
int isEmpty_s(stack stk);
void push(stack *stk, node* n);
node* pop(stack *stk);
node* peek(stack stk);