#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello";
    char str2[] = " world!";
    char str3[100];

    int length = strlen(str1);
    printf("Length of str1: %d\n", length);

    strcpy(str3, str1);
    printf("str3 after copying str1: %s\n", str3);

    strcat(str3, str2);
    printf("str3 after concatenation: %s\n", str3);

    int compare_result = strcmp(str1, str3);
    if (compare_result == 0) {
        printf("str1 and str3 are equal.\n");
    } else {
        printf("str1 and str3 are not equal.\n");
    }

    return 0;
}
