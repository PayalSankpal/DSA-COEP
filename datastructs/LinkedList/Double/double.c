#include <stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

typedef node* ASCii;

void init_ASCII(ASCii* dll){
    *dll=NULL;
}

void append(ASCii* asc, int d){
    node* nn = (node *)malloc(sizeof(node));
    if(nn){
        nn->data=d;
        nn->prev=NULL;
        nn->next=NULL;
    }
    else{
        return;
    }
    if(!(*asc)){
        *asc=nn;
        return;
    }
    nn->next=*asc;
    (*asc)->prev=nn;
    *asc=nn;
}

void ASCII_of(ASCii* asc, char alp){
    int num=alp-0;
    int dig;
    while(num){
        dig = num%10;
        append(asc, dig);
        num=(num-dig)/10;
    }
    return;
}

void traverse(ASCii asc){
    node* tail=asc;
    while(tail){
        printf("%d |",tail->data);
        tail=tail->next;
    }
    printf("%c",'\n');
    return;
}

void destroy(ASCii* asc){
    node* tail=*asc;
    while(tail){
        (*asc)=(*asc)->next;
        free(tail);
        tail = *asc;
    }
    free(*asc);
}
