#include <stdio.h>

int reverse_digits(int num) {
    	int reversed = 0;

    	while (num != 0) {
    	    int digit = num % 10;
    	    reversed = reversed * 10 + digit;
    	    num /= 10;
    	}

    	return reversed;
}

int main() {
    	int num = 12345;
    	int reversed_num = reverse_digits(num);
	
    	printf("Original number: %d\n", num);
    	printf("Reversed number: %d\n", reversedNum);
	
    	return 0;
}

