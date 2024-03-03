#include<stdio.h>

int main(){
    int row, i, j, k, count=1;
    printf("Enter number of rows:\n");
    scanf("%d", &row); 

    /*Floyd's Triangle*/
    for(i=0; i<row; i++){
        for(j=0; j<i+1; j++){
            printf("%2d ", count);
            count++;
        }
        printf("\n");  
    } 

    /*Asterick Triangle*/
    for(i=0; i<row; i++){
        for(k=0; k<row-i; k++){
            printf(" ");
        }
        for(j=0; j<(2*i+1); j++){
            printf("%s","*");
        }
        printf("\n");  
    }

    return 0;
}