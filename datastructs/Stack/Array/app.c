#include<stdio.h>
#include<ctype.h>
#include<string.h>
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
    init(&ops,50);
    char a;
    int i = strlen(exp);
    int j = 0;
    while(i!=-1){
        a = exp[i];
        if(isdigit(a)){
            postfix[j++]=a;
            if(!isdigit(exp[i+1])){
                postfix[j++]=' ';
            }
        }
        else if(a==')'){
            push(&ops,a);
        }
        else if(a=='('){
            while(!(isEmpty(ops)) && peek(ops)!=')'){
                postfix[j++]=pop(&ops);
                postfix[j++]=' ';
            }
            if(peek(ops)==')'){
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
        i--;
    }
    postfix[j]='\0';
    while(j!=-1){
        printf("%c",postfix[j]);
        j--;
    }
    printf("%c",'\n');
    return 0;
}