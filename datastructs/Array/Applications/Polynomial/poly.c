#include<stdlib.h>
#include<stdio.h>
#include"poly.h"

void init(array *arr, int n){
    arr->p=(int *)malloc(sizeof(int)*n);
    arr->size=n;
    arr->length=0;
}

void insert_at_index(array *arr,int val, int pos){
    arr->p[pos]=val;
    if(pos>=arr->length){
        arr->length=pos+1;
    }  
}


void display(array arr){
    for(int i = arr.length-1; i>=0; i--){
        printf("%dx^%d", arr.p[i],i);
        if(i!=0){
            printf("+");
        }
    }
    printf("%c",'\n');
    return;
}

void addition(array arr1,array arr2, array* sum){
    int a1=arr1.length;
    int a2=arr2.length;
    int i=0;
    while(i<a1 && i<a2){
        insert_at_index(&(*sum),arr1.p[i]+arr2.p[i],i);
        i++;
    }
    while(i<a1){
        insert_at_index(&(*sum),arr1.p[i],i);
        i++;
    }
    while(i<a2){
        insert_at_index(&(*sum),arr2.p[i],i);
        i++;
    }
}