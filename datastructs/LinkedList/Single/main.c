#include<stdio.h>
#include"linked_list.h"

int main(){
    list l1;
    init(&l1);
    insert_beg(&l1,2);
    insert_beg(&l1,1);
    insert_end(&l1,3);
    insert_end(&l1,4);
    display(l1);
    del_beg(&l1);
    del_end(&l1);
    display(l1);
    printf("%c",'\n');
    printf("The length of the list is %d",length(l1));
    destroy(&l1);
    printf("The length of the list is %d",length(l1));
    printf("%c",'\n');
    return 0;
}