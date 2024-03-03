#include <stdio.h>

int main() {
    	float arr[50];
    	int size;
    	float searchElement;
    	int index = -1;

    	printf("Enter the size of the array (up to 50): ");
    	scanf("%d", &size);
	
    	printf("Enter %d floating-point values:\n", size);
    	for (int i = 0; i < size; ++i) {
    	    scanf("%f", &arr[i]);
    	}
	
    	printf("Enter the element to search: ");
    	scanf("%f", &searchElement);
		
    for (int i = 0; i < size; ++i) {
    	    if (arr[i] == searchElement) {
    	        index = i;
    	        break;
    	    }
    	}
	
    	if (index != -1) 
    	    printf("Element found at index %d\n", index);
    	
    	else 
    	    printf("Element not found\n");
    	
	
    	return 0;
}	

