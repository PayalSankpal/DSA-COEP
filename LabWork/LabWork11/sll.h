typedef struct node{
    int data;
    struct node* next;
}node;

typedef node* sll;

void init(sll* sll);
void append(sll* sll, int n);
void reverse(node*prev_to_start, node* start, node* end);
void traverse(sll sll);
void reverse_even(sll* sll);
void insert_beg(sll* sll, int n);
void reverse_cpy(sll ll, sll* rev);
int isPalindrome(sll ll);
void remove_duplicates(sll *ll);
