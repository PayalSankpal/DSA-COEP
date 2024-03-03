#include <stdio.h>

int main(){
    char c;
    printf("Enter a character\n");
    scanf("%c", &c);
    if((c>='A')&&(c<='Z')){
        c+=('a'-'A');
    }
    else if((c>='a')&&(c<'z')){
        c-=('a'-'A');   
    }
    printf("The character is now %c\n", c);
    return 0;
}
