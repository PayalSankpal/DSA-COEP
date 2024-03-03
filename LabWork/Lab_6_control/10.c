#include <stdio.h>

int main() {
    float floatValue;

    printf("Enter a floating-point value: ");
    scanf("%f", &floatValue);

    printf("Value in exponent form (2 decimal places): %.2e\n", floatValue);
    printf("Value in exponent form (4 decimal places): %.4e\n", floatValue);

    return 0;
}

