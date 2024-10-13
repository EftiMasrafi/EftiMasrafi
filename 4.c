#include<stdio.h>
#include <string.h>

int main(){
    int n;
         printf("Enter a value: \n");
        scanf("%d", &n);
        int is_prime = 1;
        for (int i=2 ; i<n ; i++)
        {
            if (n % i == 0)
            {
                printf("Is not prime");
                is_prime = 0;
                break;

            }
        }

        if (is_prime == 1) {
            printf("Is prime");
        }

        return 0;

}
