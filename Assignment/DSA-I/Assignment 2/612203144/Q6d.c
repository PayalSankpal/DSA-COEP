#include <stdio.h>

int main(){
	int row=6, i, j, k, prev_list[50], cur_list[50], prev_len=2;
	for(i=0; i<row; i++){
		for(j=0; j<(row)-i; j++){
			printf(" ");
		}
		if(i==0){
			printf("1");
		}
		else if(i==1){
			printf("1 1");
			prev_list[0]=1;
			prev_list[1]=1;
		}
		else if(i>=2){
			cur_list[0]=1;
			cur_list[prev_len]=1;
			for (j=0; j<prev_len-1; j++){
				cur_list[j+1]=prev_list[j]+prev_list[j+1];	
			}
			
			for (k=0; k<prev_len+1; k++){
				printf("%d ", cur_list[k]);
				prev_list[k]=cur_list[k];
			}
			prev_len++;
			
		}
		printf("%c", '\n');
	}
	return 0;
}
