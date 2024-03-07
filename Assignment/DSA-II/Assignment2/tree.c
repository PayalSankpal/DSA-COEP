#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include "tree.h"

void init_bst(bst* t,int N){
    t->tree = (int *)malloc(sizeof(int)*N);
    int* p = t->tree;
    for(int i=0; i<N; i++){
        p[i]=INT_MAX;
    }
    t->size=N;
    t->length=0;
    return;
}

void insert_bst(bst* t, int n){
    int* p = t->tree;
    int i=0 ;
    while(i<t->size && p[i]!=INT_MAX){
        if(p[i]==n){
            return;
        }
        else if(p[i]>n){
            i=(2*i)+1;
        }
        else{
            i=(2*i)+2;
        }
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

void inorder(bst *t){       //non-recursive
    int * p= t->tree;
    int pos =0 , i=0, count=0;
    while(count<t->length){
        if((((2*pos)+1)>t->size) ||  (p[(2*pos)+1]==INT_MAX)){
            if(i!=(2*pos)+2){
                printf("%d ", p[pos]);
                count++;
                i=pos;
                if((2*pos)+2 < t->size){
                    pos=(2*pos)+2;
                }
                else{
                    pos=go_back(pos);
                }
            }
            else{
                pos = go_back(pos);
            }
        }
        else if(i>(2*pos)+1){
            printf("%d ",p[pos]);
            count++;
            i=pos;
            if((2*pos)+2 < t->size){
                pos=(2*pos)+2;
            }
            else{
                pos=go_back(pos);
            }
        }
        else{
            pos=(2*pos)+1;
        }
    }
    printf("\n");
    return;
}

void postorder(bst* t){
    int* p = t->tree;
    int pos=0, count=0, i=0;
    while(count<t->length){
        if((2*pos)+2!=i){
            if((2*pos)+1!=i){
                if((2*pos)+1<t->size){
                    if(p[(2*pos)+1]!=INT_MAX){
                        pos=2*pos+1;
                    }
                    else{
                        if((2*pos)+2 < t->size){
                            if (p[(2*pos)+2]!=INT_MAX){
                                pos=2*pos+2;
                            }
                        }
                        else{
                            printf("%d ",p[pos]);
                            count++;
                            i=pos;
                            pos=go_back(pos);
                        }
                    }
                }
                else{
                    printf("%d ",p[pos]);
                    count++;
                    i=pos;
                    pos=go_back(pos);
                }
            }
            else{
                if((2*pos)+2 < t->size){
                    if (p[(2*pos)+2]!=INT_MAX){
                        pos=2*pos+2;
                    }
                }
                else{
                    printf("%d ",p[pos]);
                    count++;
                    i=pos;
                    pos=go_back(pos);
                }   
            }
        }
        else{
            printf("%d ",p[pos]);
            count++;
            i=pos;
            pos=go_back(pos);
        }
    }
    printf("\n");
    return;
}

void preorder(bst* t){
    int* p = t->tree;
    int pos=0, count=0, i=0;
    while(count< t->length){
        if((2*pos)+1>i && (2*pos)+2>i){
            printf("%d ",p[pos]);
            count++;
            i=pos;
            if((2*pos)+1 < t->size){
                if(p[(2*pos)+1]!=INT_MAX){
                    pos=(2*pos)+1;
                }
                else{
                    if((2*pos)+2 < t->size){
                        if(p[(2*pos)+2]!=INT_MAX){
                            pos=(2*pos)+2;
                        }
                    }
                    else{
                        pos=go_back(pos);
                    }
                }
            }
            else{
                pos=go_back(pos);
            }
        }
        else{
            if((2*pos)+2<=i){
                if(pos!=0){
                    pos=go_back(pos);
                }
                else{
                    if((2*pos)+2 < t->size){
                        if(p[(2*pos)+2]!=INT_MAX){
                            pos=(2*pos)+2;
                        }
                    }
                    else{
                        pos=go_back(pos);
                    }
                }
                
            }
            else if((2*pos)+1==i){
                if((2*pos)+2 < t->size){
                    if(p[(2*pos)+2]!=INT_MAX){
                        pos=(2*pos)+2;
                    }
                }
                else{
                    pos=go_back(pos);
                }
            }
        }
        
    }
    printf("\n");
    return;
}

void levelwise(bst* t){
    int * p= t->tree;
    for(int i=0; i<t->size; i++){
        if(p[i]!=INT_MAX){
            printf("%d ", p[i]);
        }
    }
    printf("\n");
}


int isComplete(bst* t){
    int *p= t->tree;
    int pos = 0, flag=0;
    while(pos< t->size){
        if(p[pos]==INT_MAX && flag==0){
            flag=0
        }
        else if(p[pos]!=INT_MAX && flag==1){
            return 0
        }
        pos+=1
    }
    return 1
}
