#include <stdio.h>

char *cutonchar(char *str, char ch) {
    	char *result = str;

    	// Iterate through the characters of the string
    	while (*result != '\0' && *result != ch) {
    	    result++;
    	}
	
    	// If the character is found, replace it with null terminator
    	if (*result == ch) {
    	    *result = '\0';
    	}
	
    	return str;
}	

int main() {
    	char str1[] = "something bad";
    	char ch1 = ' ';
    	printf("Original: %s\n", str1);
    	char *result1 = cutonchar(str1, ch1);
    	printf("After cutonchar: %s\n", result1);
	
    	char str2[] = "something bad";
    	char ch2 = 'e';
    	printf("Original: %s\n", str2);
    	char *result2 = cutonchar(str2, ch2);
    	printf("After cutonchar: %s\n", result2);
	
    	return 0;
}

