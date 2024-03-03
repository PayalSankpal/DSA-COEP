typedef struct tr_node{
    char data;
    struct tr_node* left, * right;
}tr_node;

typedef tr_node* expTree;

void init_tree(expTree* t);
tr_node* create_node(char value);
void inorder(expTree t);



