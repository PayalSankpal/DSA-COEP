#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int m, n;

    printf("Enter two integers (m and n): ");
    scanf("%d %d", &m, &n);

    printf("Prime numbers from %d to %d:\n", m, n);
    for (int i = m; i <= n; ++i) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

