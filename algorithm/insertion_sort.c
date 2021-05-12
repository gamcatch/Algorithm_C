/**
삽입 정렬은 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여,
자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘이다.
주어진 데이터를 inserttion sort를 사용하여 정렬하시오. 데이터의 최대크기는 100이다. 

input 
======================
1 // 전체 Test case 수 
5 // 데이터 크기 
1 4 5 2 3

output 
=======================
#1 1 2 3 4 5
**/
#include <stdio.h>

#define MAX_NUM 100

int input[MAX_NUM];
int num;

void insertionSort(void)
{
    int temp;
    int i;
    int j;

    for (i = 1; i < num; i++)
    {
        temp = input[i];
        j = i - 1;
        while ( (temp < input[j]) && (j>=0))
        {
            input[j+1] = input[j];
            j = j - 1;
        }
        input[j+1] = temp;
    }
}

void printResult(void)
{
    int i;

    for (i = 0; i < num; i++)
    {
        printf("%d ", input[i]);
    }
    printf("\n");
}

int main(void)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/insertion_sort_input.txt", "r", stdin);

    int T;
    int test_case;
    int  i;

    scanf("%d", &T);

    for (test_case = 1; test_case <=T; test_case++)
    {
        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            scanf("%d", &input[i]);
        }
        insertionSort();
        printf("#%d ", test_case);
        printResult();
    }

    return 0;
}