#include<stdio.h>
#include "tree.h"

int main(){
    bst t1;
    init_bst(&t1, 10);
    insert_bst(&t1, 10);
    insert_bst(&t1, 2);
    insert_bst(&t1, 21);
    insert_bst(&t1, 9);
    insert_bst(&t1, 25);
    levelwise(&t1);
    inorder(&t1);
    postorder(&t1);
    preorder(&t1);
    printf("%d\n", isComplete(&t1));
    return 0;
}