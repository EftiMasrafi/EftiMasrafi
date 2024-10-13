#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    gets (str);

    printf("The length of the string \"%s\" is: %d\n", str, strlen(str));


    return 0;
}
