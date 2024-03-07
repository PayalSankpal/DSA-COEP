#include<stdlib.h>
#include<stdio.h>
#include "heap.c"

int main(){
    heap h1;
    int size = (rand()%16)+1;
    init_heap(&h1, size+10);
    int ele;
    printf("Enter %d numbers: ",size);
    for(int i = 0; i<size; i+=1){
        scanf("%d",&ele);
        insert_heap(&h1, ele);
    }
    max_heapify(&h1);
    levelwise(&h1);
    min_heapify(&h1);
    levelwise(&h1);
    return 0;
}