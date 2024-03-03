typedef struct stack{
    int size;
    int length;
    int *s;
}stack;

void init(stack* stk, int s);
int isEmpty(stack stk);
int isFull(stack stk);
void push(stack *stk, int n);
int pop(stack* stk);
int peek(stack stk);