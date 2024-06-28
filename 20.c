#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, mid;

    printf("Enter a sentence: ");
    gets(str);
    printf("Number of characters in the sentences :%d", strlen(str));
    int words = 1;
    for (int i = 0; i<strlen(str); i++){
        if (str[i] == ' '){
            words++;
        }

    }
    printf("\nNumber of words in the sentences :%d", words);

    return 0;
}
