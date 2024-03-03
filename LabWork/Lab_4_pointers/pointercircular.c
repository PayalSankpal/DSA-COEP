#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char name;
	struct node* next;
}node;

void init(node** a){
	*a = NULL;
	return;
}

void append(node** a, char d){
	node* nn;
	nn = (node*)malloc(sizeof(node));
	if(nn){
		nn->next = NULL;
		nn->name = d;
	}
	else
		return;
	

	if(*a == NULL){
		*a = nn;
		nn->next = *a;
		return;
	}
	
	node* p;
	p = *a;
	while(p->next != *a){
		printf("Hello\n");
		p = p->next;
	}
	
	p->next = nn;
	nn->next = *a;
	return;

}

int main(){

	char data;
	int choice = 1;
	node* a;
	init(&a);
	
	while(choice){
		
		printf("Enter data to add: ");
		scanf(" %c", &data);
		append(&a, data);
		
		printf("do you want to continue?(1--->yes/0--->no) ");
		scanf("%d", &choice);
	}
}
