#include<stdio.h>

int main(){
    int i;
    printf("Character  ASCII value\n");
    for(i=65; i<91; i++){
        printf("%c    %d\n",i,i);
    }
    for(i=97; i<123; i++){
        printf("%c    %d\n",i,i);
    }
    return 0;
}
