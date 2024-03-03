typedef struct node{
    int data;
    struct node* next;
}node;

typedef node* list;

void init_ll (node** head);
void insert_beg(node **head, int data);
void insert_end(node **head, int data);
void del_beg(node **head);
void del_end(node **head);
void display(list head);
node* search(list head, int n);
int length(list head);
void destroy(list *head);