#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    if (ch >= 'a' && ch <= 'z')
        printf("Lowercase alphabet\n");
    else if (ch >= 'A' && ch <= 'Z')
        printf("Uppercase alphabet\n");
    else
        printf("Not an alphabet\n");

    return 0;
}

