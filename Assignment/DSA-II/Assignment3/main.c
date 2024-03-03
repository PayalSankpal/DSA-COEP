#include<ctype.h>
#include "stack.c"
#include "stack_t.c"
#include "tree.c"

int precedence(char c){
    if(c=='+'){
        return 10;
    }
    else if(c=='-'){
        return 10;
    }
    else if(c=='*'){
        return 100;
    }
    else if(c=='/'){
        return 100;
    }
    else{
        return 0;
    }
}

int main(){
    stack  op;
    stack_t num;
    expTree et;
    init_tree(&et);
    init_st_t(&num);
    init_st(&op);
    char c;
    tr_node* create_subtree(char c){
        tr_node* parent = create_node(c);
        if(!isEmptyst_t(num)){
            parent->right=pop_t(&num);
        }
        else{
            printf("Error!");
        }
        if(!isEmptyst_t(num)){
            parent->left=pop_t(&num);
        }
        else{
            printf("Error!");
        }
        return parent;
    }

    while((c=getchar())!='\n'){
        if (isdigit(c) || isalpha(c) || c=='('){
            tr_node* nn = create_node(c);
            push_t(&num, nn);
        }
        else if(c=='+'|| c=='-'|| c=='*'|| c=='/'){
            if(isEmptyst(op)){
                push(&op, c);
            }
            else{
                while(!isEmptyst(op)){
                    char operator=pop(&op);
                    if(precedence(c)<=precedence(operator)){        //precedence 
                        tr_node* nn= create_subtree(operator);     //create_subtree;
                        push_t(&num, nn);
                    }
                    else{
                        push(&op, operator);
                        break;
                    }
                }
                push(&op, c);
            }
        }
        else if(c==')'){
            while(!isEmptyst(op)){
                char operator=pop(&op);
                if(operator=='('){
                    break;
                }      
                tr_node* nn= create_subtree(operator);     
                push_t(&num, nn);   
            }
        }
    }
    while(!isEmptyst(op)){
        push_t(&num, create_subtree(pop(&op)));
    }
    if(!isEmptyst_t(num)){
        et = pop_t(&num);
    }
    else{
        printf("Error!");
    }
    inorder(et);
    return 0;
}