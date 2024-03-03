typedef struct node{
    int data;
    struct node* next;
}node;

typedef node* clist;

void init(clist* cll);
void insert_beg(clist* cll, int n);
void insert_end(clist* cll, int n);
void del_beg(clist *cll);
void del_end(clist *cll);
int length(clist cll);
node* search(clist cll,int n);
void display(clist cll);
void destroy(clist *cll);