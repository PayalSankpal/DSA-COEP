#include "queue.c"
#include "stack.c"
#include "tree.c"


int main(){
    tree t1;
    init_tree(&t1);
    insert_recur(&t1, 10);
    insert_recur(&t1, 1);
    insert_recur(&t1, 8);
    insert_recur(&t1, 9);
    insert_recur(&t1, 6);
    insert_recur(&t1, 3);
    insert_recur(&t1, 2);
    insert_recur(&t1, 1);
    insert_recur(&t1, 12);
    insert_recur(&t1, 11);
    insert_recur(&t1, 98);
    levelwise(t1);
    inorder_nonrecur(t1);
    printf("\n");
    postorder_nonrecur(t1);
    printf("\n");
    preorder_nonrecur(t1);
    return 0;
}