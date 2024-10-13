#include <stdio.h>

int sum(int a, int b){

    return a+b;
}

int main() {
  int a, b;
  printf("Enter first number ");
  scanf("%d", &a);
  printf("\n");

  printf("Enter second number ");
  scanf("%d", &b);
  printf("\n");

  int total = sum(a,b);

  printf("Sum of the number %d", total);
}
