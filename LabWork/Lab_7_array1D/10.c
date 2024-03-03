#include <stdio.h>

int same(int arr[], int size) {
    	for (int i = 0; i < size / 2; i++) {
        	if (arr[i] != arr[size - 1 - i]) {
        	    return 0; 
        	}
    	}
    	return 1; // Same
}

int main() {
    	int arr[] = {2, 3, 15, 15, 3, 2};
    	int size = sizeof(arr) / sizeof(arr[0]);

    	if (same(arr, size))
        printf("Elements are the same from front to back.\n");
        else
        printf("Elements are not the same from front to back.\n");
    

    	return 0;
}

