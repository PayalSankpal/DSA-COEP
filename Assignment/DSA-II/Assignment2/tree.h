#define LEFT 10
#define RIGHT -10

typedef struct bst{
    int * tree;
    int size;
    int length;
}bst;

void init_bst(bst* t, int N);
void insert_bst(bst* t, int n);
void inorder(bst* t);
void postorder(bst* t);
void preorder(bst* t);
void levelwise(bst* t);
int isComplete(bst* t);
