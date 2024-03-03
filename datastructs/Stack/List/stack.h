typedef struct node{
    char data;
    struct node* next; 
}node;

typedef node* stack;

void init(stack *stk);
int isEmpty(stack stk);
void push(stack *stk, char n);
char pop(stack *stk);
char peek(stack stk);