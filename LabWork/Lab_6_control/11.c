#include <stdio.h>

int main() {
    char ch;

    do {
        printf("Enter a character (* to exit): ");
        scanf(" %c", &ch);

        if (ch != '*') {

            printf("Character: %c\n", ch);
            printf("ASCII Value: %d\n", ch);

            if (ch >= 'a' && ch <= 'z') {
                printf("Uppercase: %c\n", ch - ('a' - 'A'));
            }
            else if (ch >= 'A' && ch <= 'Z') {
                printf("Lowercase: %c\n", ch + ('a' - 'A'));
            }
        }

    } while (ch != '*');

    return 0;
}

