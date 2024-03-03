#include <stdio.h>

#define HRA_RATE 0.10
#define TA_RATE 0.05

int main() {
    	float basic_pay, hra, ta, salary;

    	printf("Enter basic pay: ");
    	scanf("%f", &basic_pay);

    	hra = HRA_RATE * basic_pay;
    	ta = TA_RATE * basic_pay;

    	salary = basic_pay + hra + ta;

    	printf("Salary: %.2f\n", salary);

    	return 0;
}

