#include <stdio.h>

void delete_duplicates(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
        	for (int j = i + 1; j < size; j++) {
        		if (arr[i] == arr[j]) {
        	        	for (int k = j; k < size - 1; k++) {
        	            		arr[k] = arr[k + 1];
        	        	}
        	        size--;
        	        j--;
        	 	}
        	}
    	}	
}

int main() {
    	int arr[] = {1, 2, 3, 2, 4, 5, 3, 6, 7};
    	int size = sizeof(arr) / sizeof(arr[0]);

    	printf("Original array:\n");
    	for (int i = 0; i < size; ++i) {
        	printf("%d ", arr[i]);
    	}
    	printf("\n");

    	delete_duplicates(arr, size);

    	printf("Array after deleting duplicates:\n");
    	for (int i = 0; i < size; ++i) {
        	printf("%d ", arr[i]);
    	}
    	printf("\n");

    	return 0;
}

