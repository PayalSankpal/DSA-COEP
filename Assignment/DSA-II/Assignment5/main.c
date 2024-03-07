#include<stdlib.h>
#include<stdio.h>
#include "heap.h"

int main(){
    heap h1, h2;
    int size = (rand()%16)+1;
    init_heap(&h1, size+10);
    init_heap(&h2, size+10);
    int ele;
    printf("Enter %d numbers: ",size);
    for(int i = 0; i<10; i+=1){
        scanf("%d",&ele);
        max_insert_heap(&h1, ele);
        min_insert_heap(&h2, ele);
    }
    printf("Max heap Tree:-\n");
    levelwise(&h1);
    printf("HeapSort(Descending):-\n");
    max_heapsort(&h1);
    printf("Min heap Tree:-\n");
    levelwise(&h2);
    printf("HeapSort(Ascending):-\n");
    min_heapsort(&h2);
    return 0;
}