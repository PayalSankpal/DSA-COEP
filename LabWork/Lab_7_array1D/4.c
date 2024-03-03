#include <stdio.h>

int main() {
    	int arr[] = {60, 700, 80, 900, 10};
    	int size = sizeof(arr) / sizeof(arr[0]);

    // Display elements in triangle pattern
    	for (int i = 0; i < size; ++i) {
    	    for (int j = 0; j <= i; ++j) {
    	        printf("%d ", arr[j]);
    	    }
    		    printf("\n");
    	}

    	return 0;
}

