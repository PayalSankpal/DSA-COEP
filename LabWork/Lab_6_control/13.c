#include <stdio.h>

int main() {
    	char input;

    	printf("Enter a character or number: ");
    	scanf(" %c", &input);

    	if (input >= '0' && input <= '9') {
        	printf("Input is a number\n");
    	}
    	else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
        	printf("Input is a character\n");



        	if (input >= 'a' && input <= 'z') {
            		printf("Lowercase character, ASCII value: %d\n", input);
        	}
        	else {
            		printf("Uppercase character, ASCII value: %d\n", input);
        	}
    	}
    	else {
        	printf("Invalid input\n");
    	}
	return 0;
}

