#include <stdio.h>

int main() {
    int count = 0, sum = 0;

    for (int i = 2; i <= 200; i += 2) {
        count++;
        sum += i;
    }


    printf("Count of even numbers: %d\n", count);
    printf("Sum of even numbers: %d\n", sum);

    return 0;
}

