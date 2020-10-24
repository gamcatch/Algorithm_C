#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, *pi;
  float f, *pf;
  pi = (int*)malloc(sizeof(int));//dynamically allocation with size int 
  pf = (float*)malloc(sizeof(float)); // dynamically allocation with size float 
  *pi = 1024;
  *pf = 3.14;
  printf("i = %d, f = %f\n", *pi, *pf);
  printf("sizeof int = %lu, sizeof float %lu\n", sizeof(int), sizeof(float));

  free(pi);//free the memory of pointer pi 
  free(pf);//free the memory of pointer pf 

  return 0;
}