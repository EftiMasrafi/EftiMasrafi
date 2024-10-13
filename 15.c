#include <stdio.h>
#include <string.h>

struct car {
    int car_id;
    int car_price;
    char car_name[50];
    char car_color[50];
};

int main() {
    struct car cars[10];


    for (int i = 0; i < 10; i++) {
        printf("Enter details for car %d:\n", i + 1);
        printf("Car ID: ");
        scanf("%d", &cars[i].car_id);
        printf("Car Price: ");
        scanf("%d", &cars[i].car_price);

        printf("Car Name: ");
        scanf(" %s", &cars[i].car_name);

        printf("car Color: ");
        scanf("%s", &cars[i].car_color);
    }

    printf("\nCar Information:\n\n");

    for (int i = 0; i < 10; i++) {
        printf("Car ID: %d\n", cars[i].car_id);
        printf("Car price: %d\n", cars[i].car_price);
        printf("Car Name: %s\n", cars[i].car_name);
        printf("Car Color: %s\n", cars[i].car_color);
    }

    return 0;
}
