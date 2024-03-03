#include<stdio.h>
#include"circular.h"

int main(){
    clist c1;
    init(&c1);
    display(c1);
    insert_end(&c1, 3);
    display(c1);
    insert_end(&c1, 4);
    display(c1);
    insert_beg(&c1, 2);
    display(c1);
    insert_beg(&c1, 1);
    display(c1);
    del_beg(&c1);
    display(c1);
    del_end(&c1);
    display(c1);
    printf("The length is %d\n",length(c1));
    node *p=search(c1,3);
    printf("The node for 3 is %d\n",p->data);
    destroy(&c1);
    display(c1);
    return 0;
}