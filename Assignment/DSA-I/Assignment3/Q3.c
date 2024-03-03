#include<stdio.h>

void add(int a[], int ele, int pos);

int main(){
    int ele, pos, a[10]={1,2,3,4,5,6,7,8,9,10}, i;

    printf("The array is ");
    for(i=0; i<10; i++){
        printf(" %d ",a[i]);
    }
    printf("%c", '\n');

    printf("Enter the element to add and the postion :\n");
    scanf("%d  %d",&ele, &pos);

    add(a,ele,pos);

    printf("The updated array is ");
    for(i=0; i<10; i++){
        printf(" %d ",a[i]);
    }
    
    return 0;
}

void add(int a[], int ele, int pos){
    int i,temp1, temp2;
    if (0<=pos-1<=9){
        temp1=a[pos-1];
        a[pos-1]=ele;
        temp2=a[pos];
        for(i=pos; i<10; i++){
            a[i]=temp1;
            temp1=temp2;
            temp2=a[i+1];
        }
    }
}