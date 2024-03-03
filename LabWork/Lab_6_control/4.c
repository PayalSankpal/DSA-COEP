#include <stdio.h>

int main() {
	float num1, num2;
	int result;


    	printf("Enter two floating-point numbers: ");
    	scanf("%f %f", &num1, &num2);


    	result = (int)(num1 + num2);


    	printf("num1: %.2f\n", num1);
    	printf("num2: %.2f\n", num2);
    	printf("result: %d\n", result);

    	return 0;
}

