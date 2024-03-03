typedef struct node{
    int coeff;
    int pow;
    struct node* next;
}node;

typedef node* poly;

void init (node** head);
void insert_end(node **head, int c, int p);
void display(poly head);
void destroy(poly *head);
void addition(poly p1, poly p2, poly* sum);
