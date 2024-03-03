#include <stdio.h>

int main() {
    char item[50];
    float price, total;
    int overnightDelivery;

    printf("Enter the item: ");
    scanf("%s", item);
    printf("Enter the price: ");
    scanf("%f", &price);
    printf("Overnight delivery (0==no, 1==yes): ");
    scanf("%d", &overnightDelivery);

    if (price < 100) {
        total = price + 20.0;
    }
    else {
        total = price + 30.0;
    }

    if (overnightDelivery == 1) {
        total += 50.0;
    }

    printf("Invoice: %s Rs.%.2f shipping Rs.%.2f total Rs. %.2f\n", item, price, total - price, total);

    return 0;
}

