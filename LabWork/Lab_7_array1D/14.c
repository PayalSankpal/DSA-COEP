#include <stdio.h>
#include <stdlib.h>

int main() {
    	int original[100];
    	int new[100];
    	int count = 0;
	
	
    	printf("Original array:\n");
    	for (int i = 0; i < 100; ++i) {
    	    original[i] = rand() % 1000 + 1;
    	    printf("%d ", original[i]);
	
	
    	    if (original[i] % 8 == 0 || original[i] % 15 == 0) {
    	        new[count++] = original[i];
    	    }
    	}
    	printf("\n");
	
    	printf("Numbers divisible by 8 or 15 (new array):\n");
    	for (int i = 0; i < count; ++i) {
    	    printf("%d ", new[i]);
    	}
    	printf("\n");
	
    	return 0;
}

