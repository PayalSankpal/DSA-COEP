#include <stdio.h>

int main() {
	float num;

    	printf("Enter a floating-point number: ");
    	scanf("%f", &num);

    	int integralPart = (int)num;
   		int rightmostDigit = integralPart % 10;
    
    	printf("Rightmost digit of integral part: %d\n", rightmostDigit);

    	return 0;
}

