#include <stdio.h>

int main() {
    float unit_charges, totalBill;

    printf("Enter electricity unit charges: ");
    scanf("%f", &unit_charges);

    if (unit_charges <= 50) {
        totalBill = unit_charges * 0.50;
    } 
    else if (unit_charges <= 150) {
        totalBill = 50 * 0.50 + (unit_charges - 50) * 0.75;
    } 
    else if (unit_charges <= 250) {
        totalBill = 50 * 0.50 + 100 * 0.75 + (unit_charges - 150) * 1.20;
    } 
    else {
        totalBill = 50 * 0.50 + 100 * 0.75 + 100 * 1.20 + (unit_charges - 250) * 1.50;
    }


    totalBill = totalBill + 0.20 * totalBill;

    printf("Total Electricity Bill: Rs. %.2f\n", totalBill);

    return 0;
}

