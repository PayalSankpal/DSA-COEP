#include <stdio.h>

int main(){
	int row=5,i,j,k;
	for(i=0; i<row; i++){
		for(j=0; j<i+1; j++){
			if (j%2!=0){
				printf("1");
			}
			else{
				printf("0");
			}
		}
		for(k=0; k<2*(row-(i+1)); k++){
			printf(" ");
		}
		for(j=0; j<i+1; j++){
			if (j%2!=0){
				printf("1");
			}
			else{
				printf("0");
			}
		}
		printf("%c", '\n');
	}
	return 0;
}

