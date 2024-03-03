#include <stdio.h>
#include <math.h>

int main() {
    float v, t, wci;

    printf("Enter wind speed (in mph): ");
    scanf("%f", &v);
    printf("Enter temperature (in Fahrenheit): ");
    scanf("%f", &t);

    if (v >= 0 && v <= 4) {
        wci = t;
    }
    else if (v >= 45) {
        wci = 1.6 * t - 55;
    }
    else {
        wci = 91.4 + (91.4 - t) * (0.0203 * v - 0.304 * sqrt(v) - 0.474);
    }

    printf("Wind Chill Index: %.2f\n", wci);

    return 0;
}

