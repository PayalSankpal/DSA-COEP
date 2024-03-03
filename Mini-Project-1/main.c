#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"linkedlist.c"
#include"cstack.c"
#include"num.c"
#include"nstack.c"



void func(){
    nstack ns;
    init_nstack(&ns);
    cstack os;
    init_cstack(&os);

    int precedence(char op){
        switch(op){
            case '+': case '-':
                return 10;
            case '*': case'/':
                return 100;
            case '(':
                return 1;
        }
    }

    number* calculate(number* num1, number* num2, char op){
        switch(op){
            case'+':
                return (addnumbers(num1,num2));
            case'-':
                return(subtractnumbers(num1,num2));
            case'*':
                return(mulnumbers(num1,num2));
            case'/':
                return(divnumbers(num1,num2));
            case'%':
                return(modulus(num1,num2));
            case'^':
                return(expo(num1,num2));
        }
    }

    void push_op(char op){
        number* operand1, *operand2;
        if(isEmpty_c(os)){
            push_c(&os,op);
            return;
        }
        while( !isEmpty_c(os) && precedence(op)<=precedence(peek_c(os))){
            char operator=pop_c(&os);
            if(!isEmpty(ns)){
                operand1 = pop(&ns);
            } 
            else{
                printf("%c\n",op);
                printf("Insufficient operands!\n");
                return;
            }
            if(!isEmpty(ns)){
                operand2 = pop(&ns);
            } 
            else{
                printf("%c\n",op);
                printf("Insufficient operands!\n");
                return;
            }
            number* result = calculate(operand2, operand1, operator);     
            if(result==NULL){
                printf("Error\n");
                main();
            }
            else{
                push(&ns, result);
            }
        }
        push_c(&os, op);
        return;
    }

    void final_cal(){
        while(!isEmpty_c(os)){
            char operator=pop_c(&os);
            number* operand1 = pop(&ns);
            number* operand2 = pop(&ns);
            number* result = calculate(operand2, operand1, operator);
            if(result==NULL){
                printf("Error\n");
            }
            else{
                push(&ns, result);
            }
        }
    }

    char c;
    while((c=getchar())!='\n' || c!= EOF ){
        char t;
        if(isdigit(c)){
            number* n=(number *)malloc(sizeof(number));
            init_num(n);
            insert_beg(&(n->p), (int)c-48);
            t = storenumber(n);
            push(&ns, n);
            if(t=='+' || t=='-' || t=='*' || t=='/' || t=='%' || t=='^'  || t=='(' || t==')'){
                if(t=='('){
                    push_c(&os,t);
                }
                else if(t==')'){
                    while( !isEmpty_c(os) && peek_c(os)!='('){  //precedence
                        char operator=pop_c(&os);
                        number* operand1 = pop(&ns);
                        number* operand2 = pop(&ns);
                        number* result = calculate(operand2, operand1, operator);     //calculate
                        push(&ns, result);
                    }
                    pop_c(&os);
                }
                else{
                    push_op(t);
                }
            }
        }
        else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%' || c=='(' || c==')'){
                if(c=='('){
                    push_c(&os,c);
                }
                else if(c==')'){
                    while( !isEmpty_c(os) && peek_c(os)!='('){  //precedence
                        char operator=pop_c(&os);
                        number* operand1 = pop(&ns);
                        number* operand2 = pop(&ns);
                        number* result = calculate(operand2, operand1, operator);     //calculate
                        push(&ns, result);
                    }
                    pop_c(&os);
                }
                else{
                    push_op(c);
                }
        }
        else{
            break;
        }
        if(t=='\n'){
            break;
        }
    }
    final_cal();
    if(!isEmpty(ns)){
        displaynumber(*pop(&ns));
    }
    else{
        ;
    }
    return;
}


int main(){
    while(1){
        func();
    }
    return 0;
}