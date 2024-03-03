#include <stdio.h>
#include <stdlib.h>

char* dectobin(int n) {
    	char* binary = (char*)malloc(33);  // Assuming 32-bit integers + 1 for null terminator
    	if (binary == NULL) {
        	printf("Memory allocation failed.\n");
        	exit(1);
    	}
	int count = 0, rem;
    	while(n != 0){
    		rem = n % 2;
    		binary[count] = (char)(rem + '0');
    		count++;
    		n = n / 2;
    	}
	
	char* start;
	char* end;
	start = &binary[0];
	end = &binary[count - 1];
	while(start < end){
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	binary[count] = '\0';
    	return binary;
}

int main() {
    	int num;

    	printf("Enter a decimal number: ");
    	scanf("%d", &num);

    	char* result = dectobin(num);

    	printf("Binary representation: %s\n", result);
    	
	
    	free(result);  // Remember to free the allocated memory
	
    	return 0;
}

