#include <stdio.h>
#include<stdlib.h>

int main() {
    	int arr = (int*)malloc(sizeof(int)*10);

    	printf("Enter 10 integers:\n");
    	for (int i = 0; i < 10; ++i) {
        	scanf("%d", &arr[i]);
    	}

    	printf("Array elements in reverse:\n");
    	for (int i = 9; i >= 0; --i) {
        	printf("%d ", arr[i]);
    	}

   	free(arr);
    	return 0;
}

