#include<stdio.h>
#include<stdlib.h>

#define LEFT 10
#define RIGHT -10

void init_tree(tree* t){
    *t = NULL;
    return;
}

node* create_node(int val){
    node* nn = (node*)malloc(sizeof(node));
    if(nn){
        nn->data=val;
        nn->left=NULL;
        nn->right=NULL;
    }
    else{
        return NULL;
    }
    return nn;
}

void insert(tree* t, int val){   //non-recursive
    node* p=*t, * q=NULL;
    int direction;
    while(p){
        q=p;
        if(p->data==val){
            return;
        }
        else if(p->data>val){
            p=p->left;
        }
        else if(p->data<val){
            p=p->right;
        }
    }
    node* nn = create_node(val);
    if(q==NULL){
        *t = nn;
        return;
    }
    if(val<q->data){
        q->left=nn;
    }
    else{
        q->right=nn;
    }
    return;
}

node* search(tree t, int val){     //non-recur
    node* p=t;
    while(p){
        if(p->data==val){
            return p;
        }
        else if(p->data>val){
            p=p->left;
        }
        else if(p->data<val){
            p=p->right;
        }
    }
    return NULL;
}

void insert_recur(tree* t, int val){        //recursive
    node* p = *t;
    if(*t==NULL){
        *t = create_node(val);
        return;
    }
    if(p->data==val){
        return;
    }
    if(p->data < val){
        insert_recur(&(p->right), val);
    }
    else{
        insert_recur(&(p->left), val);
    }
    return;
}

node* search_recur(tree t,int val){     //recursive
    node* p = t;
    if(t==NULL){
        return NULL;
    }
    if(p->data==val){
        return p;
    }
    if(p->data < val){
        search_recur((p->right), val);
    }
    else{
        search_recur((p->left), val);
    }
}

void preorder(tree t){           //recursive
    if(t){
        printf("%d ",t->data);
        preorder(t->left);
        preorder(t->right);
    }
    else{
        return;
    }
    return;
}


void inorder(tree t){
    if(t){
        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
    }
    else{
        return;
    }
    return;
}

void postorder(tree t){
    if(t){
        postorder(t->left);
        postorder(t->right);
        printf("%d ",t->data);
    }
    else{
        return;
    }
    return;
}


void inorder_nonrecur(tree t){        //non-recursive stack 
    stack s1;
    init_stack(&s1);
    node* p=t;
    while(1){
        if(p){
            push(&s1,p);
            p=p->left;
        }
        else if(!isEmpty_s(s1)){
            p=pop(&s1);
            printf("%d ", p->data);
            p=p->right;
        }
        else{
            break;
        }
    }
    return;
}

void postorder_nonrecur(tree t){
    stack a, b;
    init_stack(&a);
    init_stack(&b);
    push(&b, t);
    node* p = t, *temp=NULL;
    while( !isEmpty_s(b) || !isEmpty_s(a)){
        if (p->left){
            push(&b, p->left);
            p=p->left;
        }
        else if (!isEmpty_s(b)){
                temp = p;
                while(!isEmpty_s(b) &&  !p->left){
                    temp = pop(&b);
                    if(temp->right){
                        push(&a, temp); 
                        push(&b, temp->right);
                        p=temp->right;
                        break;
                    }
                    else{
                            printf("%d ",temp->data);
                            node* c = pop(&a);
                            while(c->right==temp){
                                printf("%d ",c->data);
                                temp=c;
                                if(!isEmpty_s(a)){
                                    c=pop(&a);
                                }
                                else{
                                    break;
                                }
                                
                            }
                            if(c!=temp){
                                push(&a, c);
                            }
                    }
                }
        }
    }      
    return;
}

void preorder_nonrecur(tree t){
    stack a, b;
    init_stack(&a);
    init_stack(&b);
    push(&b, t);
    node* p = t, *temp=NULL;
    while(!isEmpty_s(b) || !isEmpty_s(a)){
        if(!isEmpty_s(b)){
            p=pop(&b);
            printf("%d ",p->data);
            if(p->left){
                push(&b, p->left);
            }
            if(p->right){
                if(!isEmpty_s(a)){
                    temp=pop(&a);
                    if(temp->right!=p){
                        push(&a, temp);
                    }
                }
                push(&a, p);
            }
            p=p->left;
        }
        else{
            p=pop(&a);
            push(&b, p->right);
            p=p->right;
        }
    }
    return;
}

int count(tree t){
    if(!t){
        return 0;
    }
    return count(t->left) + 1 + count(t->right);
}

void removeNode(tree* t, int val){        //non-recursive
    node* p=*t, * q=NULL;
    int direction;
    while(p){               //search for the node
        if(p->data==val){
            break;
        }
        else if(p->data>val){
            q=p;
            p=p->left;
            direction=LEFT;
        }
        else if(p->data<val){
            q=p;
            p=p->right;
            direction=RIGHT;
        }
    }
    if(p->left==p->right){  //leaf node
        if(direction==LEFT){
            q->left=NULL;
        }
        else{
            q->right=NULL;
        }
        free(p);
    }
    else if(p->left!=NULL && p->right==NULL){       //left child only
        if(direction==LEFT){
            q->left=p->left;
        }
        else{
            q->right=p->left;
        }
        free(p);
    }
    else if(p->left==NULL && p->right!=NULL){       //right child only
        if(direction==LEFT){
            q->left=p->right;
        }
        else{
            q->right=p->right;
        }
        free(p);
    }
    else{                                            //both children  -- replace with left subtree largest
        node* m = p->left, *n=NULL;
        while(m->right){
            n=m;
            m=m->right;
        }
        if(m==p->left){
            p->data=m->data;
            p->left=m->left;
            free(m);
            return;
        }
        p->data=m->data;
        if(m->left){
            n->right=m->left;
        }
        else{
            n->right=NULL;
        }
        
    }
    return;
}

void levelwise(tree t){       //BFS queue
    node* p=NULL;
    queue q;
    init(&q);
    enqueue(&q, t);
    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("%d ",p->data);
        if(p->left){
            enqueue( &q, p->left);
        }
        if(p->right){
            enqueue( &q, p->right);
        }
    }
    printf("\n");
    return;
}

