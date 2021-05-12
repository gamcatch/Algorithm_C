#include <stdio.h>

void swap(char *x, char *y);
void permutation(char *list, int i, int n);

int main() {
  char s[] = "ABCDEFGHIJ";
  permutation(s,0,3);

  return 0;
}

void swap(char *x, char *y) {
  char t;
  t = *x;
  *x = *y;
  *y = t;
}

void permutation(char *list, int i, int n) {
  int j;
  if (i==n) {
    for (j=0; j<=n; j++)
      printf("%c",list[j]);
    printf("\n");
  } else {
    for (j=i; j<=n; j++) {
      swap(&list[i], &list[j]);
      permutation(list, i+1, n);
      swap(&list[i], &list[j]);
    }
  }
}