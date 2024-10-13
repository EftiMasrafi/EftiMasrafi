#include <stdio.h>


int main() {

    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int array[n];
    for (int i= 0; i<n; i++){
        printf("\nEnter value of index: [%d]: ", i);
        scanf("%d", &array[i]);
    }

        printf("\nThe elements of the array are: ");
     for (int i= 0; i<n; i++){
        printf("%d, ", array[i]);
    }
}
