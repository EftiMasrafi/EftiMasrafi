#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, mid;

    printf("Enter a string: ");
    gets(str);

    strupr(str);
    puts(str);

    return 0;
}
