
#include <stdio.h>

int main() {
    int n, f1 = 0, f2 = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        printf("%d, ", f1);
        next = f1 + f2;
        f1 = f2;
        f2 = next;
    }

    return 0;
}
