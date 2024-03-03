#include<stdio.h>

/*Q.5*/

typedef struct fraction{
    int numerator;
    int denominator;
}fraction;


int main(){

    int compare(fraction f1, fraction f2){
        if(f1.numerator == f2.numerator && f1.denominator==f2.denominator){
            return 0;
        }
        else{
            if((float)f1.numerator/f1.denominator > (float)f2.numerator/f2.denominator){
                return 1;
            }
            else{
                return -1;
            }
        }
    }

    fraction f1, f2;
    printf("Enter first fraction as num and denominator.\n");
    scanf("%d%d",&f1.numerator,&f1.denominator);
    printf("Enter second fraction as num and denominator.\n");
    scanf("%d%d",&f2.numerator,&f2.denominator);
    int com = compare(f1,f2);
    com == 0 ? printf("Equal") : ((com==-1)?printf("first fraction is less than second\n") : printf("first fraction is greater than second\n"));
    return 0;
}



