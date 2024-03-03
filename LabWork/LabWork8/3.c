#include<stdio.h>
/*Q.3*/

typedef struct hotel{
    char name[50];
    char address[100];
    char grade;
    int NumberOfRomms;
    int RoomCharges;
}hotel;

void printHotelsByGrade(hotel hotels[], int numHotels, char targetGrade) {
    printf("Hotels in Grade %c:\n", targetGrade);
    for (int i = 0; i < numHotels; i++) {
        if (hotels[i].grade == targetGrade) {
            printf("%s\n", hotels[i].name);
        }
    }
    printf("\n");
}

void printHotelsByRoomCharges(hotel hotels[], int numHotels, int maxRoomCharges) {
    printf("Hotels with Room Charges less than %d:\n", maxRoomCharges);
    for (int i = 0; i < numHotels; i++) {
        if (hotels[i].RoomCharges < maxRoomCharges) {
            printf("%s\n", hotels[i].name);
        }
    }
    printf("\n");
}

int main() {
    hotel hotels[] = {
        {"Hotel A", "Address A", 'A', 50, 100},
        {"Hotel B", "Address B", 'B', 75, 150},
        {"Hotel C", "Address C", 'A', 40, 90},
        {"Hotel D", "Address D", 'C', 60, 120},
    };

    int numHotels = sizeof(hotels) / sizeof(hotels[0]);

    printHotelsByGrade(hotels, numHotels, 'A');
    printHotelsByRoomCharges(hotels, numHotels, 110);

    return 0;
}