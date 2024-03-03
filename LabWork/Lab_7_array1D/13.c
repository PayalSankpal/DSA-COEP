#include <stdio.h>

void merge(int A[], int B[], int C[], int sizeA, int sizeB) {
    	int i = 0, j = 0, k = 0;

    	while (i < sizeA && j < sizeB) {
        	if (A[i] < B[j]) 
        	    C[k++] = A[i++];
        	
        	else 
        	    C[k++] = B[j++];
 	
    	}

   	while (i < sizeA) {
        	C[k++] = A[i++];
    	}

    	while (j < sizeB) {
        	C[k++] = B[j++];
    	}
}

int main() {
    	int A[] = {45, 50, 70, 85, 90};
    	int B[] = {30, 40, 60, 75, 80};
   	int C[10];
    	int sizeA = sizeof(A) / sizeof(A[0]);
    	int sizeB = sizeof(B) / sizeof(B[0]);
		
    	merge(A, B, C, sizeA, sizeB);
	
    	printf("Merged array in sorted order:\n");
    	for (int i = 0; i < sizeA + sizeB; ++i) {
    		printf("%d ", C[i]);
    	}
    	printf("\n");

    	return 0;
}

