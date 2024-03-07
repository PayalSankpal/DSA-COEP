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
    t->length=-1;
    return;
}

/*Helper functions*/

int go_back(int pos){
    return (pos-1)/2;
}

int removeRoot(heap* h){
    if(isEmpty(h)){
        return INT_MAX;
    }
    int n = h->tree[0];
    h->tree[0]=h->tree[h->length];
    h->length--;
    return n;
}

/*MAX heap*/

void max_insert_heap(heap* t, int n){
    int* p = t->tree;
    t->length++;
    int i=t->length;
    while( go_back(i)>=0 && n > p[go_back(i)] ){
        p[i]=p[go_back(i)];
        i=go_back(i);
        if(i==0){
            break;
        }
    }
    p[i]=n;
    return;
} 

void max_heapsort(heap* h){
    int count = h->length;
    int ele;
    for(int i=0; i<count+1; i+=1){
        printf("%d ",removeRoot(h));
        max_heapify(h);
    }
    printf("\n");
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

/*MIN heap*/

void min_insert_heap(heap* t, int n){
    int* p = t->tree;
    t->length++;
    int i=t->length;
    while( go_back(i)>=0 && n < p[go_back(i)] ){
        p[i]=p[go_back(i)];
        i=go_back(i);
        if(i==0){
            break;
        }
    }
    p[i]=n;
    return;
}


void min_heapsort(heap* h){
    int count = h->length;
    int ele;
    for(int i=0; i<count+1; i+=1){
        printf("%d ",removeRoot(h));
        min_heapify(h);
    }
    printf("\n");
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
    for(int i=0; i<t->length+1; i++){
        printf("%d ", p[i]);
    }
    printf("\n");
}

int isEmpty(heap* h){
    if(h->tree[0]==INT_MAX){
        return 1;
    }
    return 0;
}



