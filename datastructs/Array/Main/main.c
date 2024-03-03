#include<stdio.h>
#include"array.h"

int main(){
    array A1,A2;
    init(&A1,20);
    init(&A2,5);
    append(&A1,1);
    append(&A1,3);
    append(&A1,5);
    append(&A1,6);
    append(&A1,7);
    display(A1);
    insert_at_index(&A1, 2, 1);
    insert_at_index(&A1, 4, 3);
    display(A1);
    delete_at_index(&A1, 1);
    display(A1);
    printf("The maximum is %d\n", max_in_array(A1));
    printf("The minimum is %d\n", min_in_array(A1));
    append(&A2, 8);
    append(&A2, 9);
    append(&A2, 10);
    display(A2);
    merge_array(&A1,&A2);
    display(A1);
}