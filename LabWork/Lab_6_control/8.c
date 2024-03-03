#include <stdio.h>


struct GroceryItem {
    char name[50];
    int quantity;
    float price_per_unit;
};

int main() {
    struct GroceryItem items[10];
    int item_count;

    printf("Enter the number of items purchased: ");
    scanf("%d", &item_count);


    printf("Enter details for each item:\n");
    for (int i = 0; i < item_count; ++i) {
        printf("Item #%d:\n", i + 1);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Price per unit: ");
        scanf("%f", &items[i].price_per_unit);
    }


    printf("\n********************************************BILL****************************************\n");
    printf("Item\t\t\tQuantity\t\tPrice\t\t\tAmount\n");
    printf("____________________________________________________________________________________________\n");

    float totalAmount = 0;


    for (int i = 0; i < item_count; ++i) {
        float amount = items[i].quantity * items[i].price_per_unit;
        totalAmount += amount;

        printf("%s\t\t\t%d\t\t%.2f\t\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price_per_unit, amount);
    }

    printf("____________________________________________________________________________________________\n");
    printf("Total Amount to be paid = %.2f\n", totalAmount);
    printf("____________________________________________________________________________________________\n");

    return 0;
}

