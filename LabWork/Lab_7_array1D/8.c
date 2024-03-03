#include <stdio.h>
#include <stdlib.h>

int main() {
    	int c, n;
    	int array[10];  
    
    	for (c = 0; c < 10; c++) {
    	    array[c] = rand() % 51 + 50;  
	}
	
    	printf("Array of integers with values ranging from 50 to 100:\n");
    	for (c = 0; c < 10; c++) {
    	    printf("%d\n", array[c]);
    	}
	
    	return 0;
}

