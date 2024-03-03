#include <stdio.h>

void circular_shift_right(int arr[], int size, int n) {
    	for (int i = 0; i < n; ++i) {
        	int temp = arr[size - 1];
        	for (int j = size - 1; j > 0; --j) {
        	    arr[j] = arr[j - 1];
        	}
        	arr[0] = temp;
    	}	
}	

void circular_shift_left(int arr[], int size, int n) {
    	for (int i = 0; i < n; ++i) {
        	int temp = arr[0];
        	for (int j = 0; j < size - 1; ++j) {
        	    arr[j] = arr[j + 1];
        	}
        	arr[size - 1] = temp;
    	}	
}

int main() {
    	int arr[] = {1, 2, 3, 4, 5};
    	int size = sizeof(arr) / sizeof(arr[0]);
    	int shift;
	printf("Array elements: \n");
	for (int i = 0; i < size; ++i) {
    	    printf("%d ", arr[i]);
    	}
    	printf("\n");
	
    	printf("Enter the number of locations to shift: ");
    	scanf("%d", &shift);
	
    	circular_shift_right(arr, size, shift);
		
	
    	printf("Array elements after right circular shift:\n");
    	for (int i = 0; i < size; ++i) {
    	    printf("%d ", arr[i]);
    	}
    	printf("\n");
	
	
    	circular_shift_left(arr, size, shift);
	
	
    	printf("Array elements after left circular shift:\n");
    	for (int i = 0; i < size; ++i) {
    	    printf("%d ", arr[i]);
    	}
    	printf("\n");
	
    	return 0;
}

