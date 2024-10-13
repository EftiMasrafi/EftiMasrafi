#include <stdio.h>
#include <string.h>

struct customer {
    int customer_id;
    char name[50];
    float balance;
};

int main() {
    struct customer customers[5];


    for (int i = 0; i < 5; i++) {
        printf("Enter details for customer %d:\n", i + 1);
        printf("Customer ID: ");
        scanf("%d", &customers[i].customer_id);

        printf("Name: ");
        scanf(" %s", &customers[i].name);

        printf("Balance: ");
        scanf("%f", &customers[i].balance);
    }

    printf("\nCustomer Information:\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Customer ID: %d\n", customers[i].customer_id);
        printf("Name: %s\n", customers[i].name);
        printf("Balance: %.2f\n\n", customers[i].balance);
    }

    return 0;
}
