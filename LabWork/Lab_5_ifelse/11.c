#include <stdio.h>

int main() {
    float angle1, angle2, angle3;

    printf("Enter three angles of the triangle: ");
    scanf("%f %f %f", &angle1, &angle2, &angle3);

    if (angle1 + angle2 + angle3 == 180 && angle1 > 0 && angle2 > 0 && angle3 > 0)
        printf("Valid triangle\n");
    else
        printf("Invalid triangle\n");

    return 0;
}

