#include <stdio.h>

int GCD( int num1, int num2);
int LCM( int num1, int num2);


int main(){
    int num1, num2, gcd, lcm;
    printf("Enter two numbers:");
    scanf("%d%d", &num1, &num2);

    gcd=GCD(num1, num2);
    lcm=LCM(num1, num2);

    printf("The GCD is %d\n", gcd);
    printf("The LCM is %d\n", lcm);

    return 0;
}

int GCD( int num1, int num2){
    int temp, i;
    for(i=0; num2!=0; i++){
        temp = num2;
        num2= num1 % num2;
        num1 = temp;
    }
    return num1;
}

int LCM(int num1, int num2){
    int gcd = GCD(num1, num2);
    return (num1*num2)/gcd; 
}