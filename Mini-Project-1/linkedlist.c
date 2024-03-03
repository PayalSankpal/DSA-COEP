#include<stdlib.h>
#include<stdio.h>
#include"linkedlist.h"

void init_ll(node** head){
    *head = NULL;
    return;
}

void insert_beg(node **head, int data){
    list newnode;
    newnode = (list)malloc(sizeof(node));
    if(newnode){
        newnode->data=data;
        newnode->next=NULL;
    }
    else{
        return;
    }
    if(*head==NULL){
        *head=newnode;
        return;
    }
    newnode->next=*head;
    *head=newnode;
    return;
}

void insert_end(node **head, int data){
    list newnode;
    newnode = (list)malloc(sizeof(node));
    if(newnode){
        newnode->data=data;
        newnode->next=NULL;
    }
    else{
        return;
    }
    if(*head==NULL){
        *head=newnode;
        return;
    }
    list tail= *head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=newnode;
    return;
}

void del_beg(node **head){
    node *p;
    p = *head;
    if (*head==NULL){
        return;
    }
    *head = (*head)->next;
    free(p);
}

void del_end(node **head){
    node * p,* q;
    p=*head;
    if (*head==NULL){
        return;
    }
    while(p->next!=NULL){
        q = p;
        p = p->next;
    }
    q->next=NULL;
    free(p);
}

void display(list head){
    node *tail=head;
    while(tail!=NULL){
        printf("%d  |", tail->data);
        tail=tail->next;
    } 
    printf("\n");
}

node* search(list head, int n){
    node *tail = head;
    while(tail){
        if (tail->data==n){
            return tail;
        }
        tail=tail->next;
    }
    return NULL;
}

int length(list head){
    node *tail = head;
    int length=0;
    while(tail){
        length++;
        tail=tail->next;
    }
    return length;
}

void destroy(list *head){
    node *tail=*head,*p;
    while(tail){
        p=tail;
        tail=tail->next;
        free(p);
    }
    free(head);
}

