#include <stdio.h>

int main(){
    int i, j, index=1, flag=1, primes[50]={2};
    for (i=3; i<101; i++){
        flag=1;
        for(j=2; j<i; j++){
            if (i%j==0){
                flag=0;
                break;
            }
        }
        if (flag==1){
            primes[index]=i;
            index++;
        }
    }

    printf("The list of prime numbers from 1 to 100:");
    for(i=0; i<index; i++){
        printf("%d ", primes[i]);
    }
    return 0;
}