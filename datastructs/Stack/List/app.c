#include<stdio.h>
#include<ctype.h>
#include "stack.h"

int precedence(char a){
    if(a=='+'){
        return 10;
    }
    else if(a=='-'){
        return 10;
    }
    else if(a=='*'){
        return 20;
    }
    else if(a=='/'){
        return 20;
    }
    else if(a=='%'){
        return 20;
    }
    else if(a=='^'){
        return 30;
    }
    else if(a=='('){
        return 5;
    }
    return 0;
}

int main(){
    char exp[50];
    fgets(exp, sizeof(exp), stdin);
    char postfix[50];
    stack ops;
    init(&ops);
    char a;
    int i = 0;
    int j = 0;
    while(exp[i]!='\0'){
        a = exp[i];
        if(isdigit(a)){
            postfix[j++]=a;
            if(!isdigit(exp[i+1])){
                postfix[j++]=' ';
            }
        }
        else if(a=='('){
            push(&ops,'(');
        }
        else if(a==')'){
            while(!(isEmpty(ops)) && peek(ops)!='('){
                postfix[j++]=pop(&ops);
                postfix[j++]=' ';
            }
            if(peek(ops)=='('){
                pop(&ops);
            }
        }
        else {
            if(a=='+' || a=='-' || a=='*' || a=='/' || a=='%' || a=='^'){
                if(isEmpty(ops)){
                    push(&ops,a);
                }
                else{
                    while(!(isEmpty(ops) ) && precedence(peek(ops))>=precedence(a)){
                        postfix[j++]=pop(&ops);
                        postfix[j++]=' ';
                    }
                    push(&ops,a);
                }
            }
        }
        i++;
    }
    while(!isEmpty(ops)){
        postfix[j++]=pop(&ops);
        postfix[j++]=' ';
    }
    postfix[j]='\0';
    printf("%s\n",postfix);
    return 0;
}

