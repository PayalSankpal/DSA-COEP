#include<stdio.h>
#define PI 3.1427

float area_of_circle(int rad){
    float area;
    area = PI*rad*rad;
    return area;
}

void swap_values(int* a, int* b){
    int c = *a;
    *a = *b;
    *b =  c;
}

int factorial(int n){
    if(n==1){
        return 1;
    }
    return (n*factorial(n-1));
}

int main(){
    int radius;
    printf("Enter the radius of circle:\n");
    scanf("%d",&radius);
    printf("The area of the circle is %f\n",area_of_circle(radius));
    int a,b;
    printf("Enter the values of two variables:\n");
    scanf("%d%d",&a,&b);
    swap_values(&a, &b);
    printf("The swapped values of the variables are %d %d\n", a, b);
    for(int i = 1; i < 6; i++){
        printf("The facrorial of %d is %d.\n", i,factorial(i));
    }
    return 0;
}