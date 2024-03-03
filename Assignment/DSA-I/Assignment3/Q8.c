#include<stdio.h>

//declaration of functions
void upperTriMat(int a[][10], int upper[][10], int N);
void lowerTriMat(int a[][10], int lower[][10], int N);


int main(){
    int a[10][10], i, j, N, upper_mat[10][10], lower_mat[10][10];

    //input no of rows
    printf("Enter the number of rows/col(less than 10):");
    scanf("%d",&N);

    //input matrix from user
    printf("Enter matrix :\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &a[i][j]);
        }
    } 
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf(" %2d ", a[i][j]);
        }
        printf("\n");
    } 

    //function call to form upper and lower matrix
    upperTriMat(a, upper_mat, N);
    lowerTriMat(a, lower_mat, N);

    //print the matrix
    printf("The upper triangular matrix is\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf(" %2d ", upper_mat[i][j]);
        }
        printf("\n");
    }
    printf("The lower triangular matrix is\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf(" %2d ", lower_mat[i][j]);
        }
        printf("\n");
    }  

    return 0;
}

void upperTriMat(int a[][10], int upper[][10], int N){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if (j<=i){
                upper[j][i]=a[j][i];
            }
            else {
                upper[j][i]=0;
            }
        }
    } 
}

void lowerTriMat(int a[][10], int lower[][10], int N){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if (j>=i){
                lower[j][i]=a[j][i];
            }
            else {
                lower[j][i]=0;
            }
        }
    } 
}