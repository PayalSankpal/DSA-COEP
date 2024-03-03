#include <stdio.h>

int main() {
    float phy, chem, bio, math, comp;
    float total, per;

    printf("Enter marks in Physics, Chemistry, Biology, Mathematics, and Computer (out of 100): ");
    scanf("%f %f %f %f %f", &phy, &chem, &bio, &math, &comp);

    // Calculate total marks and percentage
    total = phy + chem + bio + math + comp;
    per = (total / 500) * 100;

    // Display percentage
    printf("Percentage: %.2f%%\n", per);

    // Determine the grade
    if (per >= 90)
        printf("Grade: A\n");
    else if (per >= 80)
        printf("Grade: B\n");
    else if (per >= 70)
        printf("Grade: C\n");
    else if (per >= 60)
        printf("Grade: D\n");
    else if (per >= 40)
        printf("Grade: E\n");
    else
        printf("Grade: F\n");

    return 0;
}

