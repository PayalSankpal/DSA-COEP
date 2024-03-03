#include<stdio.h>

int dec_to_bin(int num);


int main(){
    int num, count_1=0, bin[50];
    printf("Enter a num:\n");
    scanf("%d", &num);
    printf("The binary conversion is ");
    count_1=dec_to_bin(num);
    printf("\n");
    printf("The number of 1\'s is %d\n",count_1);  
    return 0;
}

int dec_to_bin(int num){
    int bin_rev[50];
    int i,j,rem,count_1=0 ;
    for(i=0; num!=0; i++){
        bin_rev[i]=num%2;
        num=num/2;
    }
    for(j=i-1; j>=0; j--){
        printf("%d", bin_rev[j]);           /*To print the binary representation in correct order*/

        if (bin_rev[j]==1){                 /*To count the number of ones in the array*/
            count_1++;
        }       
    }
    return count_1;
}


