#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    int comparison = strcmp(str1, str2);

    if (comparison < 0) {
        printf("%s is lexicographically smaller than %s\n", str1, str2);
    } else if (comparison > 0) {
        printf("%s is lexicographically smaller than %s\n", str2, str1);
    } else {
        printf("%s and %s are lexicographically equal\n", str1, str2);
    }

    return 0;
}
