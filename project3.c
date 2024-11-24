#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 30
#define MAX_CART_ITEMS 20

typedef struct {
    int id, quantity, available;
    char name[MAX_NAME_LENGTH], description[MAX_DESCRIPTION_LENGTH];
    float price;
} Product;

typedef struct {
    int id, cart_items[MAX_CART_ITEMS], cart_quantities[MAX_CART_ITEMS], cart_count;
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
} User;

Product products[MAX_PRODUCTS]; int product_count = 0;
User users[MAX_USERS]; int user_count = 0;

void save_data(const char *filename, void *data, int count, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(&count, sizeof(int), 1, file);
        fwrite(data, size, count, file);
        fclose(file);
    }
}

void load_data(const char *filename, void *data, int *count, size_t size) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fread(count, sizeof(int), 1, file);
        fread(data, size, *count, file);
        fclose(file);
    }
}

void load_initial_products() {
    if (product_count == 0) {
        Product initial_products[] = {
            {1, 100, 100, "Product1", "Description1", 9.99},
            {2, 50, 50, "Product2", "Description2", 14.99},
            {3, 200, 200, "Product3", "Description3", 19.99},
            {4, 150, 150, "Product4", "Description4", 24.99},
            {5, 300, 300, "Product5", "Description5", 29.99}
        };
        for (int i = 0; i < 5; i++) {
            products[i] = initial_products[i];
            product_count++;
        }
        save_data("products.dat", products, product_count, sizeof(Product));
    }
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Max products reached.\n");
        return;
    }
    Product *p = &products[product_count++];
    p->id = product_count;
    printf("Enter product name: ");
    scanf(" %[^\n]", p->name);
    printf("Enter description: ");
    scanf(" %[^\n]", p->description);
    printf("Enter price and quantity: ");
    scanf("%f %d", &p->price, &p->quantity);
    p->available = p->quantity;
    save_data("products.dat", products, product_count, sizeof(Product));
}

void update_product() {
    int id, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", products[i].name);
            printf("Enter new description: ");
            scanf(" %[^\n]", products[i].description);
            printf("Enter new price and quantity: ");
            scanf("%f %d", &products[i].price, &products[i].quantity);
            products[i].available = products[i].quantity;
            save_data("products.dat", products, product_count, sizeof(Product));
            printf("Product updated.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void remove_product() {
    int id, found = 0;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            for (int j = i; j < product_count - 1; j++) {
                products[j] = products[j + 1];
            }
            product_count--;
            save_data("products.dat", products, product_count, sizeof(Product));
            printf("Product removed.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void search_products(int show_all) {
    char keyword[MAX_NAME_LENGTH] = "";
    if (!show_all) {
        printf("Enter search keyword: ");
        scanf(" %[^\n]", keyword);
    }
    printf("\nID\tName\tPrice\tAvailable\n");
    for (int i = 0; i < product_count; i++) {
        if (show_all || strstr(products[i].name, keyword) || strstr(products[i].description, keyword)) {
            printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].available);
        }
    }
}

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("Max users reached.\n");
        return;
    }
    User *u = &users[user_count++];
    u->id = user_count;
    printf("Enter username: ");
    scanf("%s", u->username);
    printf("Enter password: ");
    scanf("%s", u->password);
    save_data("users.dat", users, user_count, sizeof(User));
}

int login() {
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return users[i].id;
        }
    }
    return -1;
}

void add_to_cart(int user_id) {
    int product_id, quantity;
    printf("Enter product ID and quantity: ");
    scanf("%d %d", &product_id, &quantity);
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == product_id && products[i].available >= quantity) {
            for (int j = 0; j < user_count; j++) {
                if (users[j].id == user_id) {
                    if (users[j].cart_count < MAX_CART_ITEMS) {
                        users[j].cart_items[users[j].cart_count] = product_id;
                        users[j].cart_quantities[users[j].cart_count++] = quantity;
                        products[i].available -= quantity;
                        save_data("products.dat", products, product_count, sizeof(Product));
                        save_data("users.dat", users, user_count, sizeof(User));
                        printf("Added to cart.\n");
                        return;
                    } else {
                        printf("Cart full.\n");
                    }
                }
            }
        }
    }
    printf("Product not found or insufficient quantity.\n");
}

void view_cart(int user_id) {
    float total = 0;
    printf("\nYour shopping cart:\nID\tName\tPrice\tQuantity\tTotal\n");
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == user_id) {
            for (int j = 0; j < users[i].cart_count; j++) {
                int prod_id = users[i].cart_items[j], qty = users[i].cart_quantities[j];
                for (int k = 0; k < product_count; k++) {
                    if (products[k].id == prod_id) {
                        float item_total = products[k].price * qty;
                        printf("%d\t%s\t%.2f\t%d\t%.2f\n", products[k].id, products[k].name, products[k].price, qty, item_total);
                        total += item_total;
                        break;
                    }
                }
            }
            printf("Total: %.2f\n", total);
            return;
        }
    }
    printf("Cart not found.\n");
}

void checkout(int user_id) {
    view_cart(user_id);
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == user_id) {
            users[i].cart_count = 0;
            printf("Order placed.\n");
        }
    }
    save_data("users.dat", users, user_count, sizeof(User));
}

void customer_menu(int user_id) {
    int choice;
    do {
        printf("\n1. View Products\n2. Add to Cart\n3. View Cart\n4. Checkout\n0. Logout\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: search_products(1); break;
            case 2: add_to_cart(user_id); break;
            case 3: view_cart(user_id); break;
            case 4: checkout(user_id); break;
        }
    } while (choice != 0);
}

void admin_menu() {
    int choice;
    do {
        printf("\n1. Add Product\n2. Update Product\n3. Remove Product\n4. Search Products\n0. Logout\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_product(); break;
            case 2: update_product(); break;
            case 3: remove_product(); break;
            case 4: search_products(1); break;
        }
    } while (choice != 0);
}

void main_menu() {
    int choice, logged_user_id;
    do {
        printf("\nWelcome to the Super Shop!\n1. Register\n2. Login as Customer\n3. Login as Admin\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: register_user(); break;
            case 2: if ((logged_user_id = login()) > 0) customer_menu(logged_user_id); else printf("Login failed.\n"); break;
            case 3: admin_menu(); break;
        }
    } while (choice != 0);
    save_data("products.dat", products, product_count, sizeof(Product));
    save_data("users.dat", users, user_count, sizeof(User));
}

int main() {
    load_data("products.dat", products, &product_count, sizeof(Product));
    load_data("users.dat", users, &user_count, sizeof(User));
    load_initial_products();
    main_menu();
    return 0;
}