#include<stdlib.h>
#include<stdio.h>
#include"array.h"

void init(array *arr, int n){
    arr->p=(int *)malloc(sizeof(int)*n);
    arr->size=n;
    arr->length=0;
}

void append(array *arr,int val){
    arr->p[(arr->length)++]=val;
}

void insert_at_index(array *arr,int val, int pos){
    int temp = arr->p[pos], temp2;
    arr->p[pos]=val;
    for(int i = pos+1; i<arr->length+1; i++){
        temp2 = arr->p[i];
        arr->p[i]=temp;
        temp=temp2;
    }
    arr->length++;
}

void delete_at_index(array *arr, int pos){
    int temp;
    for(int i = pos; i<arr->length-1; i++){
        temp=arr->p[i+1];
        arr->p[i]=temp;
    }
    arr->length--;
}

void display(array arr){
    for(int i = 0; i<arr.length; i++){
        printf("%d |", arr.p[i]);
    }
    printf("%c",'\n');
    return;
}

int max_in_array(array arr){
    int max=arr.p[0];
    for(int i = 1; i<arr.length; i++){
        if (max<arr.p[i]){
            max=arr.p[i];
        }
    }
    return max;
}

int min_in_array(array arr){
    int min=arr.p[0];
    for(int i = 1; i<arr.length; i++){
        if (min>arr.p[i]){
            min=arr.p[i];
        }
    }
    return min;
}

void reverse_the_array(array *arr){
    int *p;
    p = (int *)malloc(sizeof(int)*arr->size);
    for(int i = 0; i<arr->length; i++){
        p[i]=arr->p[(arr->length-1)-i];
    }
    arr->p = p;
    return;
}

void merge_array(array *arr1, array *arr2){
    if ((arr2->length+arr1->length)<arr1->size){
        for(int i = 0; i<arr2->length; i++){
            arr1->p[arr1->length+i]=arr2->p[i];
        }
        arr1->length+=arr2->length;
        return;
    }
    else{
        printf("Overflow error");
        return;
    }
}


