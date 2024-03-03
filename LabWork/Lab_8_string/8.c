#include <stdio.h>

#define PI 3.14159265358979323846
#define EPSILON 1e-10

long long factorial(int n) {
    	if (n == 0 || n == 1)
        	return 1;
    	else
        	return n * factorial(n - 1);
}

double power(double base, int exponent) {
    	double result = 1.0;
    	for (int i = 0; i < exponent; i++) {
        	result *= base;
    	}
    	return result;
}

// Sine function 
double my_sin(double x) {
    	double result = 0.0;
    	for (int n = 0; n < 10; n++) {
    		result += power(-1, n) * power(x, 2 * n + 1) / factorial(2 * n + 1);
    	}
    	return result;
}

// Sine-inverse function 
double my_asin(double x) {
	double result = x;
    	double term = x;
    	int n = 1;
    	
    	//term = (term . x^2 . (2n - 1)^2) / 2n(2n+1)
    	//result = result + (term  / 2n + 1)
	    	
    	while (term > EPSILON || term < -EPSILON) {
        	term *= x * x * (2 * n - 1) * (2 * n - 1) / (2 * n * (2 * n + 1));
        	result += term / (2 * n + 1);
        	n++;
    	}
    	return result;

}

// Cosine function 
double my_cos(double x) {
    	double result = 0.0;
    	for (int n = 0; n < 10; n++) {
        	result += power(-1, n) * power(x, 2 * n) / factorial(2 * n);
    	}
    	return result;
}

// Cosine-inverse function 
double my_acos(double x) {
    	double result = PI / 2 - my_asin(x);
    	return result;
}

// Tangent function using sine and cosine functions
double my_tan(double x) {
    	return my_sin(x) / my_cos(x);
}

int main() {
    	double x = 0.5;
    	x = PI * x / 180;
   	printf("sin: %lf ", my_sin(x));
	printf("cos: %lf ", my_cos(x));
	printf("asin: %lf ", my_asin(x));
	printf("acos: %lf ", my_acos(x));
	printf("tan: %lf ", my_tan(x));
	
    	return 0;
}

