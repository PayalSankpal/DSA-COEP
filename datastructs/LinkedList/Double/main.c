#include<stdio.h>
#include"double.c"

int main() {
    ASCii L1;
    init_ASCII(&L1);
    ASCII_of(&L1,'z');
    traverse(L1);
    destroy(&L1);
    traverse(L1);
    return 0;
}