#include<stdlib.h>
#include<stdio.h>
#include"sll.h"

void init(sll* sll){
    *sll = NULL;
    return;
}

void append(sll* sll, int n){
    node* nn = (node *)malloc(sizeof(node));
    if(nn){
        nn->data=n;
        nn->next=NULL;
    }
    else{
        return;
    }
    if(*sll==NULL){
        *sll=nn;
        return;
    }
    node* tail = *sll;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=nn;
    return;
}

void reverse(node*prev_to_start, node* start, node* end){
    node *prev = start;
    node *curr = prev->next;
    node *test=end->next;
    prev->next=end->next;
    node*next;
    while(curr!=test){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    prev_to_start->next=prev;
}

void traverse(sll sll){
    node* tail = sll;
    while(tail){
        printf("%d |",tail->data);
        tail=tail->next;
    }
    printf("%c",'\n');
    return;
}

void reverse_even(sll* sll){
    node* tail = *sll;
    node *start=NULL, *end=NULL, *prev=NULL, *prev_to_start=NULL;
    while(tail){
        if(tail->data%2==0){
            if(start){
                end=tail;
            }
            else{
                start=tail;
                prev_to_start=prev;
            }
        }
        else{
            if(start && end){
                reverse(prev_to_start, start, end);
                start=NULL;
                end=NULL;
            }
        }
        prev=tail;
        tail=tail->next;
    }
}

void insert_beg(sll* sll, int n){
    node* nn = (node *)malloc(sizeof(node));
    if(nn){
        nn->data=n;
        nn->next=NULL;
    }
    else{
        return;
    }
    if(*sll==NULL){
        *sll=nn;
        return;
    }
    nn->next=*sll;
    *sll=nn;
}

void reverse_cpy(sll ll, sll* rev){
    node* tail =ll;
    while(tail){
        insert_beg(&(*rev), tail->data);
        tail=tail->next;
    }
}

int isPalindrome(sll ll){
    sll rev;
    init(&rev);
    reverse_cpy(ll, &rev);
    node* t1=ll;
    node* t2=rev;
    while(t1 && t2){
        if(t1->data!=t2->data){
            return 0;
        }
        t1=t1->next;
        t2=t2->next;
    }
    if(t1 || t2){
        return 0;
    }
    return 1;
}

void remove_duplicates(sll *ll){
    node*tail=*ll;
    while(tail){
        node*prev=tail;
        node *tt=tail->next;
        while(tt){
            if(tail->data==tt->data){
                prev->next=tt->next;
            }
            prev=tt;
            tt=tt->next;
        }
        tail=tail->next;
    }
}