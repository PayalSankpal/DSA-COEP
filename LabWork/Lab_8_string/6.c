#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrcasecmp(char* str1, char* str2) {
    	while (*str1 && *str2) {
        	int diff = tolower((int)*str1) - tolower((int)*str2);
        	if (diff != 0) {
            		return diff;
        	}
        	str1++;
        	str2++;
    	}

    	return tolower((int)*str1) - tolower((int)*str2);
}


char* myStrsep(char** str, char* delim) {
    	if (*str == NULL || **str == '\0') {
        	return NULL;
    	}

    	char* tokenStart = *str;
    	//strpbrk searches for the first occurence of the delimiter in the string
    	char* tokenEnd = strpbrk(tokenStart, delim);

    	if (tokenEnd != NULL) {
        	*tokenEnd = '\0';
        	*str = tokenEnd + 1;
    	}
    	else {
        	*str = NULL;
    	}

    	return tokenStart;
}


int myStrcoll( char* str1, char* str2) {

    	while (*str1 && (*str1 == *str2)) {
        	str1++;
        	str2++;
    	}

    	return *(unsigned char*)str1 - *(unsigned char*)str2;
}

int main(){

	char str1[] = "HelloWorld";
	char str2[] = "Hello";	 

	printf("string case compare\n");
	printf("%d \n", myStrcasecmp(str1, str2));
	
	char input[] = "apple,orange,banana";
    	char* token;
    	char* rest = input;
	char* delimiter = ",";

    	while ((token = myStrsep(&rest, delimiter)) != NULL) {
        	printf("Token: %s\n", token);
    	}

	char str1_new[] = "Hello";
    	char str2_new[] = "World";

    	int result = myStrcoll(str1_new, str2_new);

    	if (result < 0) 
        	printf("%s is before %s\n", str1_new, str2_new);
   
    	else if (result > 0) 
        	printf("%s is after %s\n", str1_new, str2_new);
    	else 
        printf("%s and %s are equal\n", str1_new, str2_new);
    
	return 0;

}


