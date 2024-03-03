#include<stdio.h>
#include<ctype.h>
#include"list.h"

void create_poly(char *poly1, poly* p1){
    int p=0,c=0, flag=0;
    int i = 0;
    while(poly1[i]!='\0'){
        if(isdigit(poly1[i])){
            if (flag==0){
                if(c!=0){
                    c*=10;
                }
                c += poly1[i]-'0';
            }
            else{
                p= poly1[i]-'0';
            }
        }
        else if(poly1[i]=='x'){
            if(poly1[i+1]=='+' || poly1[i+1]=='\0'){
                p=1;
            }
            if(i-1<0|| poly1[i-1]=='+'){
                c=1;
            }
        }
        else if(poly1[i]=='^'){
            flag=1;
        }
        else if(poly1[i]=='+'){
            insert_end(&(*p1),c,p);
            c=0;
            p=0;
            flag=0;
        }
        i++;
    }
    insert_end(&(*p1),c,p);
}

int main(){
    char poly1[50];
    char poly2[50];
    poly p1, p2, sum;
    init(&sum);
    init(&p1);
    init(&p2);
    gets(poly1);
    create_poly(poly1, &p1);
    display(p1);
    gets(poly2);
    create_poly(poly2, &p2);
    display(p2);
    addition(p1, p2, &sum);
    display(sum);
    return 0;
}