#include<stdio.h>

//declaration of functions
int diagonalSum(int a[3][3]);


int main(){
    int a[3][3], i, j, diag_sum;

    //input matrix from user
    printf("Enter matrix of 3x3:\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d", &a[i][j]);
        }
    } 

    //function call to return sum
    diag_sum=diagonalSum(a);

    //print the sum
    printf("The sum of the diagonal elements is %d\n", diag_sum);

    return 0;
}

int diagonalSum(int a[3][3]){
    int sum=0, i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if (i==j){
                sum+=a[i][j];
            }
        }
    } 
    return sum;
}