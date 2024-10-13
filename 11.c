#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, mid;

    printf("Enter a string: ");
    gets(str);

    char temp[100];
    len = strlen(str);
    int j = 0;
    for (int i = len/2; i<len; i++){
        temp[j] = str[i];
        j++;
    }

    strcat(temp, str);
    puts(temp);

    return 0;
}
