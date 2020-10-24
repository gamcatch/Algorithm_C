#include <stdio.h>

int main() {
  int i, *pi; //declare i and its pointer
  pi = &i; // get the address of i 

  i = 10;
  printf("i = %d\n", i);
  printf("pi = %p\n", pi);//print the address stored in pointer pi
  printf("*pi = %d\n", *pi);//print the value addressed by pointer pi

  return 0;
}