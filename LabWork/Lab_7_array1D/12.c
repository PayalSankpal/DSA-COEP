#include <stdio.h>
#include <stdlib.h>

void nearest(int arr[], int size, int key) {
	//setting index at -1 as nearest lesser and greater	
    	int lesser = -1, greater = -1;

	//if the element we are on is less or greater than the one fixed assign it the lesser variable
    	for (int i = 0; i < size; ++i) {
        	if (arr[i] < key && (lesser == -1 || arr[i] > arr[lesser])){
            		lesser = i;
        	}
        	if (arr[i] > key && (greater == -1 || arr[i] < arr[greater])) {
            		greater = i;
        }
   	}
	if(lesser != -1){
    		printf("Nearest lesser element: %d\n", arr[lesser]);
    	}
    	if(greater != -1){
    		printf("Nearest greater element: %d\n", arr[greater]);
    		return;
    	}
    	else
    		return;
    	
}

int main() {
    	int arr[] = {1, 5, 10, 15, 20};
    	int size = sizeof(arr) / sizeof(arr[0]);
    	int key;

    	printf("Enter the key element: ");
    	scanf("%d", &key);

    	nearest(arr, size, key);

    	return 0;
}

