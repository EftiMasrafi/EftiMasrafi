#include <stdio.h>
#include <string.h>

int main() {
    char str1[50];
    char str2[50];

    printf("Enter first word: ");
    gets(str1);
    printf("\n");

      printf("Enter second word: ");
    gets(str2);
    printf("\n");

    if (strlen(str1) < strlen(str2)){
        strcat(str1, str2);
        puts(str1);
    }
    else{
        strcat(str2, str1);
        puts(str2);
    }

}
