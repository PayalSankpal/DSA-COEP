#include<stdio.h>

//declaration of functions
void addition(int a[3][3], int b[3][3], int result[3][3]);
void subtraction(int a[3][3], int b[3][3], int result[3][3]);
void multiplication(int a[3][3], int b[3][3], int result[3][3]);

int main(){
    int a[3][3], b[3][3], i, j, choice, result[3][3];

    //menu
    printf("Calculation Menu for matrix:-\n");
    printf("1.Addition\n");
    printf("2.Subtraction\n");
    printf("3.Multiplication\n");
    scanf("%d", &choice);

    //input matrix from user
    printf("Enter first array of 3x3:\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter second array of 3x3:\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d", &b[i][j]);
        }
    }

    
    //cases for option chosen
    switch(choice){
        case 1:
            addition(a, b, result);
            break;
        case 2:
            subtraction(a, b, result);
            break;
        case 3:
            multiplication(a, b, result);
            break;
        default:
            printf("Invalid choice\n"); 
    }

    printf("The result of operation is :\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf(" %2d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void addition(int a[3][3], int b[3][3], int result[3][3]){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            result[i][j]=a[i][j]+b[i][j];
        }
    }
}

void subtraction(int a[3][3], int b[3][3], int result[3][3]){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            result[i][j]=a[i][j]-b[i][j];
        }
    }
}

void multiplication(int a[3][3], int b[3][3], int result[3][3]){
    int i,j,k;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
                if (k!=0){
                    result[i][j]+=a[i][k]*b[k][j];
                }
                else{
                    result[i][j]=a[i][k]*b[k][j];
                } 
            }
        }
    }
}

