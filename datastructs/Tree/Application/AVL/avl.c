#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void initAVL(avl* t){
    *t=NULL;
    return;
}

node* create_node(int val, char* c){
    node * nn = (node*)malloc(sizeof(node));
    if(!nn){
        return NULL;
    }
    nn->mis=val;
    nn->Name=strdup(c);
    nn->left=NULL;
    nn->right=NULL;
    nn->parent=NULL;
    nn->bf=0;
}

int height(avl t){
    if(t==NULL){
        return 0;
    }
    int lh = height(t->left);
    int rh = height(t->right);
    if(lh>rh){
        return lh+1;
    }
    else{
        return rh+1;
    }
}

void calculateBF(avl* t){
    if(*t==NULL){
        return;
    }
    node* p = *t;
    while(p){
        p->bf = height(p->left) - height(p->right);
        p=p->parent;
    }
    return;
}

void RR(avl* t, avl* m){
    node* p = *t;
    node* q = p->right;
    p->right = q->left;
    if(q->left){
        q->left->parent = p;
    }
    q->parent = p->parent;
    if(p->parent){
        if(p->parent->mis > p->mis){
            p->parent->left = q;
        }
        else{
            p->parent->right = q;
        }
    }
    else{
        *m = q;
    }
    q->left = p;
    p->parent = q;
    calculateBF(&p);
}

void LL(avl* t, avl* m){
    node* p = *t;
    node* q = p->left;
    p->left = q->right;
    if(q->right){
        q->right->parent=p;
    }
    q->parent = p->parent;
    if(q->parent){
        if(p->parent->mis > p->mis){
            p->parent->left = q;
        }
        else{
            p->parent->right = q;
        }
    }
    else{
        *m = q;
    }
    q->right = p;
    p->parent = q;
    calculateBF(&p);
    return;
}

void RL(avl* t, avl* m){
    RR(&((*t)->left), m);
    LL(t, m);
}

void LR(avl* t, avl* m){
    LL(&((*t)->right), m);
    RR(t, m);
}


void adjustBF(avl* t, avl* m){
    node* p = *t;
    while(p){
        if(p->bf > 1){
            if(p->left->bf > 0){
                LL(&p, m);
            }else{
                RL(&p, m);
            }
        }
        else if(p->bf < -1){
            if(p->right->bf < 0){
                RR(&p, m);
            }
            else{
                LR(&p, m);
            }
        }
        p=p->parent;
    }
}


void insertNode(avl* t, int val, char* c){
    if(*t==NULL){
        *t=create_node(val, c);
        return;
    }
    node* p= *t, *q=NULL;
    while(p){
        q=p;
        if(p->mis==val){
            return;
        }
        else if(p->mis < val){
            p=p->right;
        }
        else{
            p=p->left;
        }
    }
    if(q->mis < val){
        q->right = create_node(val, c);
        q->right->parent=q;
        calculateBF(&(q->right));
        adjustBF(&(q->right), t);
    }
    else{
        q->left = create_node(val, c);
        q->left->parent=q;
        calculateBF(&(q->left));
        adjustBF(&(q->left), t);
    }
    return;
}

void removeNode(avl* t, int val){
    if(*t ==  NULL){
        return;
    }
    node * p =*t,* q= NULL;
    while(p){
        if(p->mis == val){
            break;
        }
        else if(p->mis < val){
            q=p;
            p=p->right;
        }
        else{
            q=p;
            p=p->left;
        }
    }
    if(!p){
        return;
    }
    if(p->left==NULL && p->right==NULL){   //leaf node
        if(val > q->mis){
            q->right=NULL;
        }
        else{
            q->left=NULL;
        }
        free(p);
        calculateBF(&q);
        adjustBF(&q, t);
    }
    else if(p->left!=NULL && p->right==NULL){       //left child only
        if(q->mis > val){
            q->left=p->left;
        }
        else{
            q->right=p->left;
        }
        p->left->parent = q;
        free(p);
        calculateBF(&q);
        adjustBF(&q, t);
    }
    else if(p->left==NULL && p->right!=NULL){       //right child only
        if(q->mis > val){
            q->left=p->right;
        }
        else{
            q->right=p->right;
        }
        p->right->parent = q;
        free(p);
        calculateBF(&q);
        adjustBF(&q, t);
    }
    else{                                            //both children  -- replace with left subtree largest
        node* m = p->left, *n=NULL;
        while(m->right){
            n=m;
            m=m->right;
        }
        if(m==p->left){
            p->mis=m->mis;
            p->Name=m->Name;
            p->left=m->left;
            if(m->left){
                m->left->parent = p;
            }
            free(m);
            calculateBF(&p);
            adjustBF(&p, t);
            return;
        }
        p->mis=m->mis;
        p->Name=m->Name;
        n->right=m->left;
        if(m->left){
            m->left->parent = n;
        }
        free(m);
        calculateBF(&n);
        adjustBF(&n, t);
        return;
    }

}

void traverse(avl t){                           //preorder
    if(!t){
        return;
    }
    printf("Name: %s, Balance Factor: %d", t->Name, t->bf);
    if(t->parent){
        printf(", Parent: %s\n", t->parent->Name);
    }
    else{
        printf("\n");
    }
    traverse(t->left);
    traverse(t->right);
}

void destroy(avl* a){
    node* t = *a;
    if(t==NULL){
        return;
    }
    destroy(&(t->left));
    destroy(&(t->right));
    free(t);
    *a = NULL;
    return;
}