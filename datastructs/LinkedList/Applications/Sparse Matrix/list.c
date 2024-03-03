#include<stdio.h>
#include<stdlib.h>
#include"list.h"

void init(spmatrix* spm){
	*spm = NULL;
	return;
}

void append(spmatrix* spm, int r, int c, int v){
	node* newnode;
	node* tail;
	newnode = (node*)malloc(sizeof(node));
	if(newnode){
		newnode->row=r;
		newnode->col=c;
		newnode->data=v;
		newnode->next=NULL;
	}
	else{
		return;
	}
	if(!(*spm)){
		*spm = newnode;
		return;
	}
	tail = *spm;
	while(tail->next){
		tail=tail->next;
	}
	tail->next=newnode;
	return;
}

void display(spmatrix spm, int row, int col){
	int r=0;
	int c=0;
	node *tail =spm, *prev=NULL;
	while(tail){
		while(r<row){
			if(tail->row==r){
				while(c<col){
					if(tail->col>c){
						printf("%2d ",0);
					}
					else if (tail->col==c){
						printf("%2d ",tail->data);
						prev=tail;
						tail=tail->next;
						c++;
						break;
					}
					c++;
				}
				if(prev){
					break;
				}
			}
			else{
				while(c<col){
					printf("%2d ",0);
					c++;
				}
				
			}
			r++;
			c=0;
			printf("%c",'\n');
		}
		
	}
	while(c<col){
		printf("%2d ",0);
		c++;
	}
	printf("%c",'\n');
	
}

spmatrix addition(spmatrix sp1, spmatrix sp2){
	spmatrix spadd;
	init(&spadd);
	node *tail1=sp1;
	node *tail2=sp2;
	while(tail1 && tail2){
		if(tail1->row < tail2->row){
			append(&spadd,tail1->row,tail1->col,tail1->data);
			tail1=tail1->next;
		}
		else if(tail1->row == tail2->row){
			if(tail1->col == tail2->col){
				append(&spadd, tail1->row, tail1->col, tail1->data+tail2->data);
				tail1=tail1->next;
				tail2=tail2->next;
			}
			else if (tail1->col < tail2->col){
				append(&spadd,tail1->row,tail1->col,tail1->data);
				tail1=tail1->next;
			}
			else{
				append(&spadd,tail2->row,tail2->col,tail2->data);
				tail2=tail2->next;
			}
		}
		else{
			append(&spadd,tail2->row,tail2->col,tail2->data);
			tail2=tail2->next;
		}
	}
	while(tail1 != NULL){
		append(&spadd, tail1->row, tail1->col, tail1->data);
		tail1=tail1->next;
	}
	while(tail2 != NULL){
		append(&spadd, tail2->row, tail2->col, tail2->data);
		tail2=tail2->next;
	}
	return spadd;
}

spmatrix subtraction(spmatrix sp1, spmatrix sp2){
	spmatrix spdiff;
	init(&spdiff);
	node *tail1=sp1;
	node *tail2=sp2;
	while(tail1 && tail2){
		if(tail1->row < tail2->row){
			append(&spdiff,tail1->row,tail1->col,tail1->data);
			tail1=tail1->next;
		}
		else if(tail1->row == tail2->row){
			if(tail1->col == tail2->col){
				append(&spdiff, tail1->row, tail1->col, tail1->data-tail2->data);
				tail1=tail1->next;
				tail2=tail2->next;
			}
			else if (tail1->col < tail2->col){
				append(&spdiff,tail1->row,tail1->col,tail1->data);
				tail1=tail1->next;
			}
			else{
				append(&spdiff,tail2->row,tail2->col,-(tail2->data));
				tail2=tail2->next;
			}
		}
		else{
			append(&spdiff,tail2->row,tail2->col,-(tail2->data));
			tail2=tail2->next;
		}
	}
	while(tail1 != NULL){
		append(&spdiff, tail1->row, tail1->col, tail1->data);
		tail1=tail1->next;
	}
	while(tail2 != NULL){
		append(&spdiff, tail2->row, tail2->col, -(tail2->data));
		tail2=tail2->next;
	}
	return spdiff;
}


