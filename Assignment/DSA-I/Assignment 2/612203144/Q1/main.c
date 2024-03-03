#include<stdio.h>

int sum_nat_num_for(int n);
int sum_nat_num_while(int n);

int main(){
    int num,sumf,sumw;
    printf("Enter a number\n");
    scanf("%d", &num);
    sumf=sum_nat_num_for(num);
    sumw=sum_nat_num_while(num);
    printf("The sum of first %d natural numbers using for loop is %d\n", num, sumf);
    printf("The sum of first %d natural numbers using while loop is %d\n", num, sumw);
    return 0;
}

int sum_nat_num_for(int n){
    int i,sum=0;
    for (i=1; i<=n; i++){
        sum+=i;
    }
    return sum;
}

int sum_nat_num_while(int n){
    int i=1,sum=0;
    while (i<=n){
        sum+=i;
        i++;
    }
    return sum;
}

