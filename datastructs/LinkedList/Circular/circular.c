#include<stdlib.h>
#include<stdio.h>
#include"circular.h"

void init(clist* cll){
    *cll=NULL;
    return;
}

void insert_beg(clist* cll, int n){
    node* nn = (node*) malloc(sizeof(node));
    if(nn){
        nn->data=n;
        nn->next=*cll;
    }
    else{
        return;
    }
    if(*cll==NULL){
        *cll = nn;
        nn->next=*cll;
    }
    node* tail = *cll;
    while(tail->next!=(*cll)){
        tail=tail->next;
    }
    *cll=nn;
    tail->next=*cll;
}

void insert_end(clist* cll, int n){
    node* nn = (node*) malloc(sizeof(node));
    if(nn){
        nn->data=n;
        nn->next=NULL;
    }
    else{
        return;
    }
    if(!(*cll)){
        *cll = nn;
        nn->next = (*cll);
    }
    node* tail = *cll;
    while(tail->next!=(*cll)){
        tail=tail->next;
    }
    tail->next=nn;
    nn->next=*cll;
}

void del_beg(clist *cll){
    if(!(*cll)){
        return;
    }
    node* tail = *cll;
    while(tail->next!=(*cll)){
        tail=tail->next;
    }
    node* p = *cll;
    (*cll)=(*cll)->next;
    tail->next = *cll;
    free(p);
    return;
}

void del_end(clist* cll){
    if(!(*cll)){
        return;
    }
    node* tail = *cll;
    node* prev;
    while(tail->next!=(*cll)){
        prev=tail;
        tail=tail->next;
    }
    node* p =tail;
    prev->next=(*cll);
    free(p);
    return;
}

int length(clist cll){
    if(!cll){
        return 0;
    }
    node* tail = cll->next;
    int count=1;
    while(tail!=cll){
        count++;
        tail=tail->next;
    }
    return count;
}

node* search(clist cll,int n){
    node* tail=cll;
    do{
        if (tail->data==n){
            return tail;
        }
        tail=tail->next;
    }while(tail!=cll);
    return NULL;
}

void display(clist cll){
    if(!cll){
        return;
    }
    node* tail = cll;
    printf("%d ",tail->data);
    tail=tail->next;
    while(tail!=cll){
        printf("%d ",tail->data);
        tail=tail->next;
    }
    printf("%c",'\n');
}

void destroy(clist *cll){
    node* tail=(*cll)->next;
    node* p;
    do{
        p = tail;
        tail=tail->next;
        free(p);
    }while(tail!=(*cll));
    free(tail);
    *cll=NULL;
    free(*cll);
    return;
}
