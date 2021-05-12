/**
계수 정렬(counting sort)는 항목들의 순서를 결정하기 위해 집합에 각 항목이 몇개씩 있는 지 세는 작업을 하면서 정렬하는 알고리즘이다. 
주어진 정수들을 Counting Sort를 이용하여 정렬하고 오름차순으로 출력하라.
(주어진 정수들은 중복 가능))

input  
============================
2    // # of test case 
10   // # of data set 
0 2 9 4 5 1 0 7 3 9
5
4 9 5 1 3

output 
===========================
#1 0 0 1 2 3 4 5 7 9 9 
#2 1 3 4 5 9
**/
#include <stdio.h>

#define MAX_N 100
#define MAX_DIGIT 10

int N; // # of data set
int arr[MAX_N];
int cnt[MAX_DIGIT];
int sortedArr[MAX_N];

void calculateDigitNumber()
{
    for (int i =0; i < N; i++)
    {
        cnt[arr[i]]++;
    }

    for (int i=1; i < MAX_DIGIT; i++)
    {
        cnt[i] = cnt[i-1] + cnt[i];
    }
}

void executeCountingSort()
{
    for (int i=N-1; i>=0; i--)
    {
        sortedArr[--cnt[arr[i]]] = arr[i];
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/counting_sort_input.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for (int test_case = 1; test_case <=T; test_case++)
    {
        scanf("%d", &N);

        for (int i =0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }

        // initialize
        for (int i=1; i < MAX_DIGIT; i++)
        {
            cnt[i] = 0;
        }

        calculateDigitNumber();
        executeCountingSort();

        // print the sorted digits 
        printf("#%d ", test_case);
        for (int i =0; i < N; i++)
        {
            printf("%d ", sortedArr[i]);
        }
        printf("\n");
    }
}
