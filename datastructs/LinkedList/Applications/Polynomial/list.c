
#include<stdlib.h>
#include<stdio.h>
#include"list.h"

void init (node** head){
    *head = NULL;
    return;
}


void insert_end(node **head, int c, int p){
    poly newnode;
    newnode = (poly)malloc(sizeof(node));
    if(newnode){
        newnode->coeff=c;
        newnode->pow=p;
        newnode->next=NULL;
    }
    else{
        return;
    }
    if(*head==NULL){
        *head=newnode;
        return;
    }
    poly tail= *head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=newnode;
    return;
}


void display(poly head){
    node *tail=head;
    while(tail!=NULL){
        printf("%dx^%d",tail->coeff,tail->pow);
        if(tail->next!=NULL){
            printf("+");
        }
        tail=tail->next;
    } 
    printf("%c",'\n');
}



void destroy(poly *head){
    node *tail=*head,*p;
    while(tail){
        p=tail;
        tail=tail->next;
        free(p);
    }
    free(head);
}

void addition(poly p1, poly p2, poly* sum){
    node* t1=p1;
    node* t2=p2;
    while(t1 && t2){
        if (t1->pow==t2->pow){
            insert_end(&(*sum), t1->coeff+t2->coeff, t1->pow);
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->pow > t2->pow){
            insert_end(&(*sum), t1->coeff, t1->pow);
            t1=t1->next;
        }
        else{
            insert_end(&(*sum), t2->coeff, t2->pow);
            t2=t2->next;
        }
    }
    while(t1){
        insert_end(&(*sum), t1->coeff, t1->pow);
        t1=t1->next;
    }
    while(t2){
        insert_end(&(*sum), t2->coeff, t2->pow);
        t2=t2->next;
    }
}
