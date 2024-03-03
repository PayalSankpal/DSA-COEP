#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include "poly.h"


void create_poly(char * poly1, array* p1){
    int c =0, p = 0;
    int flag = 0;
    int hpow=0;
    int i = 0;
    while(poly1[i]!='\0'){
        char a = poly1[i];
        if(isdigit(a)){
            if(flag==0){
                if(c!=0){
                    c*=10;
                }
                c+=a-'0';
            }
            else{
                p+=a-'0';
            }
        }
        else if(a=='x'){
            if(poly1[i+1]=='\0' || poly1[i+1]=='+'){
                p=1;
            }
            if(i-1 < 0){
                c=1;
            }
            if(i-1>0 && poly1[i-1]=='+'){
                c=1;
            }
            
        }
        else if(a=='^'){
            flag=1;
        }
        else if(a=='+'){
            insert_at_index(p1, c, p);
            if(hpow==0){
                while(p!=0){
                    insert_at_index(p1,0,--p);
                }
                hpow=1;
            }
            c=p=flag=0;
        }
        i++;
    }
    if(c!=0){
        insert_at_index(p1, c, p);
        if(hpow==0){
            while(p!=0){
                insert_at_index(p1,0,--p);
            }
            hpow=1;
        }
    }
}

int main(){
    char poly1[50];
    gets(poly1);
    array p1;
    init(&p1, 50);
    create_poly(poly1, &p1);
    display(p1);
    char poly2[50];
    gets(poly2);
    array p2;
    init(&p2,50);
    create_poly(poly2,&p2);
    display(p2);
    array sum;
    init(&sum,50);
    addition(p1,p2,&sum);
    display(sum);
    return 0;
}
