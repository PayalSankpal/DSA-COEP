#include <stdio.h>

int main() {
    int numbers[10];


    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &numbers[i]);
    }


    for (int i = 0; i < 10; ++i) {
        printf("%d, ", numbers[i]);
        if ((i + 1) % 3 == 0)
            printf("\n");
    }

    return 0;
}

