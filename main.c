#include <stdio.h>

int main(void) {
  int a[3] = {1, 2, 3};
  int l = sizeof(a)/sizeof(a[0]);

  for (int i =0; i < l ; i++) {
    printf("%d\n",a[i]);
  }
  return 0;
}