#include <stdio.h>

int main() {
    int m, n;

    printf("Enter two integers (m and n): ");
    scanf("%d %d", &m, &n);

    printf("Odd numbers from %d to %d:\n", m, n);
    for (int i = m; i <= n; ++i) {
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}

