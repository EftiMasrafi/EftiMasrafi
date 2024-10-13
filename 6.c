#include <stdio.h>


int isEven(int n){
    if (n%2 == 0){
        return 1;
    }
    else{
        return 0;
    }

}

int main() {

    int value;
    printf("Enter a value\n");
    scanf("%d", &value);

    if (isEven(value)){
        printf("True");
    }
    else {
        printf("False");
    }

    return 0;


}
