#include<stdio.h>
#include"list.h"

int main(){
	int a[4][3]={0,0,0,1,0,2,0,6,1,7,0,0};
	int b[4][3]={0,1,1,0,0,3,0,7,0,0,4,0};
	spmatrix sp1, sp2, addsp, diffsp;
	init(&sp1);
	init(&sp2);
	for(int i =0; i<4; i++){
		for(int j=0; j<3;j++){
			if(a[i][j]!=0){
				append(&sp1, i, j, a[i][j]);
			}
		}
	}
	for(int i =0; i<4; i++){
		for(int j=0; j<3;j++){
			if(b[i][j]!=0){
				append(&sp2, i, j, b[i][j]);
			}
		}
	}
	display(sp1, 4, 3);
	printf("%c",'\n');
	display(sp2, 4, 3);
	printf("%c",'\n');
	addsp=addition(sp1,sp2);
	display(addsp,4,3);
	printf("%c",'\n');
	diffsp=subtraction(sp1,sp2);
	display(diffsp,4,3);
	return 0;
}
