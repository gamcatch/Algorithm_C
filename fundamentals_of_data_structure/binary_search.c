#include <stdio.h>

int compare(int x, int y);
int binary_search(int list[], int search_num, int left, int right);

int main() {
  int n[30];
  int i;
  int num;
  int result;

  // generate nums to be sorted
  for (i=0; i<=30; i++){
    n[i] = i;
  }

  for (i=0; i<30;i++) {
    printf("%d ", n[i]);
  }

  printf("\n");

  printf("search for a integer in array: ");
  scanf("%d", &num);

  result = binary_search(n, num, 0, 30);

  if (result != -1) {
    printf("index of %d:%d\n", num, result);
  }
  else {
    printf("no such entry!\n");
  }

  return 0;
}

int compare(int x, int y) {
  if (x < y)
    return -1;
  else if (x == y)
    return 0;
  else;
    return 1;
}

int binary_search(int list[], int search_num, int left, int right) {
  int middle;
  while (left <= right) {
    middle = (left + right)/2;
    switch(compare(list[middle], search_num)) {
      case -1:
        left = middle + 1;
        break;
      case 0:
        return middle;
      case 1:
        right = middle -1;
    }
  }
  return -1;
}