#include<stdio.h>
#include"array.h"

int main(){
    array A1;
    init(&A1,20);
    append(&A1,1);
    append(&A1,10);
    append(&A1,5);
    append(&A1,100);
    append(&A1,71);
    display(A1);
    b_sort(&A1);
    display(A1);
    printf("The number 5 is at index %d\n", search(A1,5));
    printf("The number 11 is at index %d\n", search(A1,11));
    return 0;
}