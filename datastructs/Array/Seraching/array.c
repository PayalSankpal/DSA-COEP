#include<stdlib.h>
#include<stdio.h>
#include<math.h>
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

/*linear search
int search(array arr, int n){
    for(int i=0; i<arr.length; i++){
        if(arr.p[i]==n){
            return i;
        }
    }
    return -1;
}*/

//binary search
int search(array arr, int n){
    int high=arr.length-1;
    int low=0, mid;
    while(low<=high){
        mid = low + floor((high-low)/2);
        if (arr.p[mid]==n){
            return mid;
        }
        else if(arr.p[mid] < n){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}


//Selection Sort
void swap(array* arr, int i, int j){
    int temp = arr->p[i];
    arr->p[i] = arr->p[j];
    arr->p[j] =temp;
}

void sort(array *arr){
    int key, min;
    for(int i=0; i<arr->length-1; i++){
        min = i;
        for(int j = i+1; j<arr->length; j++){
            if(arr->p[j]<arr->p[min]){
                min = j;
            }
        }
        swap(arr,i,min);
    }
}

//Insertion sort
void i_sort(array* arr){
    int key;
    for(int i = 1; i<arr->length; i++){
        key = arr->p[i];
        while(i>0 && key<arr->p[i-1]){
            arr->p[i]=arr->p[i-1];
            i=i-1;
        }
        arr->p[i]=key;
    }
}

//bubble sort
void b_sort(array* arr){
    int sorted=0;
    for (int i=0; i<arr->length-1 && sorted==0; i++){
        sorted=1;
        for(int j=0; j<arr->length-1-i; j++){
            if(arr->p[j]>arr->p[j+1]){
                swap(arr,j,j+1);
                sorted=0;
            }
        }
    }
}


