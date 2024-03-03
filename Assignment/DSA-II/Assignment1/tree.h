typedef struct node {
    int MIS;
    char* Name;
    struct node *left, *right;
} node;

typedef node* BST;

void initBST(BST* t);
void insertNode(BST* t, int MIS, const char* Name);
int Count(BST t);
void removeNode(BST* t, int MIS);
node* search(BST t, int MIS);
void inorder(BST t);
void preorder(BST t);
void postorder(BST t);



