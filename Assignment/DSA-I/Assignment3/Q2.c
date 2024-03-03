#include<stdio.h>

int main(){
    int i, a[10], b[10];
    // Input the array 
    printf("Enter an array of 10 numbers:\n");
    for(i=0; i<10; i++){
        scanf("%d",&a[i]);
    }
    // store in reversed array 
    for(i=0; i<10; i++){
        b[9-i]=a[i];
    }
    // print reversed array
    printf("The reversed array:");
    for(i=0; i<10; i++){
         printf(" %d ",b[i]);
    }
    return 0;
}