#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // char
    printf("Char - Signed: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("Char - Unsigned: 0 to %u\n", UCHAR_MAX);

    // short
    printf("Short - Signed: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Short - Unsigned: 0 to %u\n", USHRT_MAX);

    // int
    printf("Int - Signed: %d to %d\n", INT_MIN, INT_MAX);
    printf("Int - Unsigned: 0 to %u\n", UINT_MAX);

    // long
    printf("Long - Signed: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Long - Unsigned: 0 to %lu\n", ULONG_MAX);

    // float
    printf("Float: %.10e to %.10e\n", FLT_MIN, FLT_MAX);

    // double
    printf("Double: %.10e to %.10e\n", DBL_MIN, DBL_MAX);

    // long double
    printf("Long Double: %.10Le to %.10Le\n", LDBL_MIN, LDBL_MAX);

    return 0;
}
