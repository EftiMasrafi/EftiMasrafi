#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of matrix ");
    scanf("%d", &n);

    int mt[n][n];

    for (int i = 0;i<n; i++){
        for (int j = 0; j<n; j++){
            scanf("%d", &mt[i][j]);
        }
    }

    int sumA = 0;
    printf("Primary Diagonal values: ");
    for(int i =0; i<n; i++){
        printf("%d, ", mt[i][i]);
        sumA = sumA + mt[i][i];
    }
    printf("\nSum of primary diagonal: %d", sumA);

    int sumB = 0;
    printf("\nSecondary Diagonal values: ");
    int j = n-1;
    for(int i =0; i<n; i++){
        printf("%d, ", mt[i][j]);
        sumB = sumB + mt[i][j];
        j--;

    }
    printf("\nSum of secondary diagonal: %d", sumB);

    return 0;

}
