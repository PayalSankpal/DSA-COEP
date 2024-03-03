#include<stdio.h>

//declaration of functions
void rowColSum(int a[3][3], int sum_row[3], int sum_col[3]);
 

int main(){
    int a[3][3], i, j, sum_row[3], sum_col[3];

    //input matrix from user
    printf("Enter matrix of 3x3 :\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d", &a[i][j]);
        }
    } 

    //function call for sum
    rowColSum(a, sum_row, sum_col);

    //print the sum
    for(i=0; i<3; i++){
       printf("The sum of %d column is %d\n", i, sum_col[i]);
    }
    for(i=0; i<3; i++){
       printf("The sum of %d row is %d\n", i, sum_row[i]);
    }

    return 0;
}

void rowColSum(int a[3][3], int sum_row[3], int sum_col[3]){
    int cur_sum_row=0,cur_sum_col=0, i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cur_sum_row+=a[i][j];
            cur_sum_col+=a[j][i];
        }
        sum_row[i]=cur_sum_row;
        sum_col[i]=cur_sum_col;
        cur_sum_row=0;
        cur_sum_col=0;
    }
}