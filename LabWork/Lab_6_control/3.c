#include <stdio.h>

int main() {
	char text[100];
	int count = 0;


    	printf("Enter text: ");
    	scanf("%s", text);


    	for (int i = 0; text[i] != '\0'; ++i) {
        	char ch = text[i];
        	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        	    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        	    count++;
        	}
    	}	


    	printf("No. of vowels: %d\n", count);

    	return 0;
}

