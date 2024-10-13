#include <stdio.h>

int main() {
    int rows ;
    int cols ;
    printf("Enter the number of rows:\n");
    scanf("%d",&rows);
    printf("Enter the number of cols:\n");
    scanf("%d",&cols);
    int array [rows][cols];
    printf("Enter Value:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
        scanf("%d",&array [i][j]);
        }
    }
    int sum = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum += array[i][j];
        }
    }

    printf("The sum of all the numbers in the 2D array is: %d\n", sum);

    return 0;
}
