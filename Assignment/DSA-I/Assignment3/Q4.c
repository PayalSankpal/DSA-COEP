#include<stdio.h>

int del(int a[], int ele);

int main(){
    int ele, a[10]={1,2,3,4,5,6,7,8,9,10}, i, new_size;

    printf("The array is ");
    for(i=0; i<10; i++){
        printf(" %d ",a[i]);
    }

    printf("\n");

    printf("Enter the element to del :\n");
    scanf("%d", &ele);

    new_size=del(a,ele);

    printf("The updated array is ");
    for(i=0; i<new_size; i++){
        printf(" %d ",a[i]);
    }
    
    return 0;
}

int del(int a[], int ele){
    int i,j, new_size;
    for(i=0; i<10; i++){
        if (a[i]==ele){
            for(j=i; j<9; j++){
                a[j]=a[j+1];
            }
            new_size=10-1;
        }
    }
    return new_size;
}