/**
순열조합(permutation combination), 순열은 순서가 부여된 임의의 집합을 다른 순서로 뒤섞는 연산이며, 조합은 집합에서 일부 원소를 취해 부분 집합을 만드는 방법을 말한다.
주어진 문자열 str (길이 n)에 대해 아래 두 가지를 차례로 출력하시오.
1. str의 n개 character를 일렬로 배열하는 모든 경우를 출력하시오.
2. str의 n개 character 중 k개를 취하는 모든 경우를 출력하시오.
(제한사항: 주어진 string에 동일한 알파벳이 중복으로 포함되지 않음. String의 maximum size는 10. k <= n.)

input
============================
1 // # of test case 
ABCD
3 // n 
2 // k

output
============================
#1
ABC
ACB
BAC
BCA
CBA
CAB
AB
AC
BC

**/
#include <stdio.h>

#define MAX_STRING_LENGTH 10

int stackTop = 0;
char combinationStack[MAX_STRING_LENGTH];

void swap(char *x, char* y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permutation(char *str, int l, int r)
{
    if (l == r)
    {
        printf("%s\n", str);
    }
    else 
    {
        for (int i = l; i <=r; i++)
        {
            swap((str+l), (str+i));
            permutation(str, l+1, r);
            swap((str+l), (str+i)); //backtrack
        }
    }
}

void push(char ch)
{
    combinationStack[stackTop++] = ch;
    combinationStack[stackTop] = '\0';
}

void pop()
{
    combinationStack[--stackTop] = '\0';
}

void combination(const char* str, int length, int offset, int k)
{
    if (k==0)
    {
        printf("%s\n", combinationStack);
        return;
    }

    for (int i = offset; i<=length-k; ++i)
    {
        push(str[i]);
        combination(str, length, i+1, k -1);
        pop();
    }
}

int main()
{
   setbuf(stdout, NULL);
   freopen("./algorithm/permutation_combination_input.txt", "r", stdin);

   int N, K, T;
   char str[MAX_STRING_LENGTH];
   scanf("%d", &T);

   for (int test_case = 1; test_case <= T; test_case++)
   {
       scanf("%s%d%d", str, &N, &K);
       str[N] = 0;
       printf("#%d\n", test_case);

       permutation(str, 0, N-1);
       combination(str, N, 0, K);
   }
   return 0; 
}