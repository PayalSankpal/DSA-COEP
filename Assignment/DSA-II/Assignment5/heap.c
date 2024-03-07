#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include "heap.h"

void init_heap(heap* t,int N){
    t->tree = (int *)malloc(sizeof(int)*N);
    int* p = t->tree;
    for(int i=0; i<N; i++){
        p[i]=INT_MAX;
    }
    t->size=N;
    t->length=0;
    return;
}

void insert_heap(heap* t, int n){
    int* p = t->tree;
    int i=0 ;
    while(i<t->size && p[i]!=INT_MAX){
        i+=1;
    }
    if(i<t->size){
        p[i]=n;
        t->length++;
    }
    return;
} 

int go_back(int pos){
    if(pos%2!=0){
        return (pos-1)/2;
    }
    else{
        return (pos-2)/2;
    }
}

void max_heapify(heap* h){
    if(isEmpty(h)){
        return;
    }
    int *p = h->tree;
    int pos_outer=go_back(h->length-1), pos=pos_outer;
    int temp=0, lc=0, rc=0;
    while(pos_outer > -1){
        pos=pos_outer;
        while(pos<(h->length)){
            if(p[(2*pos)+1]>p[(2*pos)+2] || p[(2*pos)+2]==INT_MAX){
                if(p[(2*pos)+1]>p[pos]){
                    temp=p[pos];
                    p[pos]=p[(2*pos)+1];
                    p[(2*pos)+1]=temp;
                }
                lc=(2*pos)+1;
                if((2*lc)+1 < h->length ){
                    pos=lc;
                }
                else{
                    break;
                }
            }
            else if(p[(2*pos)+1]< p[(2*pos)+2] && p[(2*pos)+2]!=INT_MAX){
                if(p[(2*pos)+2]>p[pos]){
                    temp=p[pos];
                    p[pos]=p[(2*pos)+2];
                    p[(2*pos)+2]=temp;
                }
                rc=(2*pos)+2;
                if((2*rc)+1 < h->length ){
                    pos=rc;
                }
                else{
                    break;
                }
            }
        }
        pos_outer-=1;
    }
}

void min_heapify(heap* h){
    if(isEmpty(h)){
        return;
    }
    int *p = h->tree;
    int pos_outer=go_back(h->length-1), pos=pos_outer;
    int temp=0, lc=0, rc=0;
    while(pos_outer > -1){
        pos=pos_outer;
        while(pos<(h->length)){
            if(p[(2*pos)+1]>p[(2*pos)+2]){
                if(p[(2*pos)+2]<p[pos]){
                    temp=p[pos];
                    p[pos]=p[(2*pos)+2];
                    p[(2*pos)+2]=temp;
                }
                rc=(2*pos)+2;
                if((2*rc)+1 < h->length ){
                    pos=rc;
                }
                else{
                    break;
                }
            }
            else if(p[(2*pos)+1] <= p[(2*pos)+2]){
                if(p[(2*pos)+1]<p[pos]){
                    temp=p[pos];
                    p[pos]=p[(2*pos)+1];
                    p[(2*pos)+1]=temp;
                }
                lc=(2*pos)+1;
                if((2*lc)+1 < h->length ){
                    pos=lc;
                }
                else{
                    break;
                }
            }
        }
        pos_outer-=1;
    }
}



void levelwise(heap* t){
    int * p= t->tree;
    for(int i=0; i<t->size; i++){
        if(p[i]!=INT_MAX){
            printf("%d ", p[i]);
        }
    }
    printf("\n");
}

int isEmpty(heap* h){
    if(h->tree[0]==INT_MAX){
        return 1;
    }
    return 0;
}



