typedef struct node{
    char* Name;
    int bf, mis;
    struct node* left, * right, * parent;
}node;

typedef node* avl;

void initAVL(avl* t);
void insertNode(avl* t, int val ,char* c);
void removeNode(avl* t, int val);
void traverse(avl t);
void destroy(avl* t);