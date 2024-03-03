typedef struct node{
    int data;
    struct node* left, *right;
}node;

typedef node* tree;

void init_tree(tree* t);
node* create_node(int val);
void preorder(tree t);
void inorder(tree t);
void postorder(tree t);
int count(tree t);
void insert(tree* t, int val);
node* search(tree t, int val);
void removeNode(tree* t, int val);


