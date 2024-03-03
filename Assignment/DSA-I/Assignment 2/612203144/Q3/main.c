#include<stdio.h>

int main(){
    int i, j, num, num_array[50], sum=0;
    printf("Enter a number \n");
    scanf("%d", &num);
    i=0;
    while (num!=0){
        num_array[i]=num%10;
        num/=10;
        i++;
    }
    for(j=0; j<i; j+=2){
        sum+=num_array[j];
    }
    printf("The sum of even digits is %d\n", sum);
    return 0;
}