#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getIntegerFromString(char *str) {
	int result = 0;
    	for (int i = 0; str[i] != '\0'; i++) {
        	if (!isdigit(str[i])) {
            		printf("String contains non-digit characters.\n");
            	return -1;
        	}
        	result = result * 10 + (str[i] - '0');
    	}

    	return (result);
}

int main() {
    	char str[] = "12345";
    	int result = getIntegerFromString(str);

    	if (result != -1) {
    	    printf("Integer representation: %d\n", result);
    	}

    	return 0;
}

