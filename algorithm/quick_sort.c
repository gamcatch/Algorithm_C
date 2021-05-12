/**
퀵 정렬은 기준키(pivot)를 기준으로 작거나 같은 값을 지닌 데이터는 앞으로,
큰 값을 지닌 데이터는 뒤로 가도록 하여 작은 값을 갖는 데이터와 큰 값을 갖는 데이터로 분리해가며 정렬하는 방법이다.
주어진 데이터를 Quick Sort를 사용하여 정렬 하시오. 데이터의 최대 크기는 100이다. 
**/
#include <stdio.h>

#define MAX_NUM 100

int input[MAX_NUM];
int num;

void quickSort(int first, int last)
{
    int pivot;
    int i;
    int j;
    int temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while(i<j)
        {
            while(input[i] <= input[pivot] && i < last)
            {
                i++;
            }
            while(input[j] > input[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }

        temp = input[pivot];
        input[pivot] = input[j];
        input[j] = temp;

        quickSort(first, j - 1);
        quickSort(j+1, last);
    }
}

void printResult(void)
{
    int i;

    for (i=0; i < num; i++)
    {
        printf("%d ", input[i]);
    }
    printf("\n");
}

int main(void)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/quick_sort_input.txt", "r", stdin);

    int T;
    int test_case;
    int i;

    scanf("%d", &T);

    for (test_case = 1; test_case <=T; test_case++)
    {
        scanf("%d", &num);
        for (i=0; i < num; i++)
        {
            scanf("%d", &input[i]);
        }
        quickSort(0, num - 1);
        printf("#%d ", test_case);
        printResult();
    }

    return 0;
}