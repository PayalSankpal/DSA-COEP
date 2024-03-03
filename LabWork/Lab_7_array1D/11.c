#include <stdio.h>

void reverse(int arr[], int size) {
    	for (int i = 0; i < size / 2; i++) {
        	int temp = arr[i];
        	arr[i] = arr[size - 1 - i];
        	arr[size - 1 - i] = temp;
    	}
    	return;
}

int main() {
    	int arr[] = {10, 45, 3216, 88};
    	int size = sizeof(arr) / sizeof(arr[0]);

    	reverse(arr, size);

    	printf("Reversed array:\n");
    	for (int i = 0; i < size; i++) {
        	printf("%d ", arr[i]);
    	}
    	printf("\n");

    	return 0;
}

