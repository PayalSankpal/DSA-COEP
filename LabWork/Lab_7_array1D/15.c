#include <stdio.h>

void find_second_largest(int arr[], int size) {
    	int first, second;

    	if (size < 2) {
    	    printf("Array has less than two elements.\n");
    	    return;
    	}
	
    	first = second = arr[0];
	
    	for (int i = 1; i < size; ++i) {
    	//if element is greater than first largest
    	    if (arr[i] > first) {
    	        second = first;
    	        first = arr[i];
    	    }
    	    //if element is less than first largest but greater than second largest
    	    else if (arr[i] > second && arr[i] != first)
    	        second = arr[i];
    	}
	
    	printf("Second largest element: %d\n", (second != first) ? second : -1);
}

int main() {
    	int arr[] = {10, 30, 20, 50, 40};
    	int size = sizeof(arr) / sizeof(arr[0]);
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
    	find_second_largest(arr, size);

    	return 0;
}

