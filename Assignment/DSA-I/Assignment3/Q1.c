#include<stdio.h>

int main(){
    int i, j, a[10], max1=0, max2=0;
    float avg;

    printf("Enter an array of 10 numbers:\n");
    for(i=0; i<10; i++){
        scanf("%d",&a[i]);
    }

    for(j=0; j<10; j++){
        if (a[j]> max1 && a[j]<max2){
            max1=a[j];
        }
        else if (a[j]>max1 && a[j]>max2){
            max1=max2;
            max2=a[j];
        }

    }

    avg=((float)max1+(float)max2)/2;

    printf("The average of largest two numbers is %f", avg);

    return 0;
}