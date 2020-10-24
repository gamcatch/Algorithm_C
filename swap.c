#include <stdio.h>

#define SWAP_XOR(a, b) \
 { \
   (a) ^= (b); \
   (b) ^= (a); \
   (a) ^= (b); \
 }

 #define SWAP_TYPE(type, a, b) \
  { \
    type __swap_temp; \
    __swap_temp = (b); \
    (b) = (a); \
    (a) = __swap_temp; \
  }

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y)=(t)) // swap using MACRo

void swap(int *x, int *y); //declare function with pass by reference 

int main() {

  int a = 1, b = 10, t;
  printf("a = %d, b= %d\n", a, b);
  
  printf("after swap:\n");
  swap(&a, &b);//perform swapping
  printf("a = %d, b = %d\n", a, b);

  printf("after swap:\n");
  SWAP(a, b, t);//perform swapping
  printf("a = %d, b = %d\n", a, b);

  printf("after swap:\n");
  SWAP_XOR(a, b);//perform swapping
  printf("a = %d, b = %d\n", a, b);
  
  printf("after swap:\n");
  SWAP_TYPE(int, a, b);//perform swapping
  printf("a = %d, b = %d\n", a, b);

  return 0;
}

void swap(int *x, int *y) {// function body
  int temp = *x;
  *x = *y;
  *y = temp;
}