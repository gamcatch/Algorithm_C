/**
이진 검색 알고리즘(binary search algorithm)은 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘이며, 처음 중간의 값을 임의의 값으로 선택하여, 그 값과 찾고자 하는 값의 크고 작음을 비교하는 방식을 채택하고 있다. 처음 선택한 중앙값이 만약 찾는 값보다 크면 그 값은 새로운 최고값이 되며, 작으면 그 값은 새로운 최하값이 된다. 
정렬된 정수배열에서 Binary Search를 이용하여 제시된 숫자들을 찾아라. 있으면 해당 인덱스를 출력하고, 없으면 -1 를 출력하라.
(2 ≤ M ≤ 100)
**/
#include <stdio.h>

#define MAX_M 100

int T; // # of test case 
int M; // # of element in array
int N; // # of numbers to search
int arr[MAX_M];

void binarySearch(int* arr, int low, int high, int target)
{
    int mid;
    if (low > high)
    {
        printf("-1 ");
        return;
    }

    mid = (low + high) / 2;

    if (target < arr[mid])
    {
        binarySearch(arr, low, mid -1, target);
    }
    else if (arr[mid] < target)
    {
        binarySearch(arr, mid + 1, high, target);
    }
    else 
    {
        printf("%d ", mid);
        return;
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/binary_search_input.txt", "r", stdin);

    int targetValue;
    scanf("%d", &T);

    for (int test_case = 1; test_case <=T; test_case++)
    {
        printf("#%d ", test_case);
        scanf("%d %d", &M, &N);

        for (int i = 0; i < M; i++)
        {
            scanf("%d", &arr[i]);
            //printf("%d ", arr[i]);
        }

        for (int i =0; i < N; i++)
        {
            scanf("%d", &targetValue);
            //printf("%d ", targetValue);
            binarySearch(arr, 0, M-1, targetValue);
        }
        printf("\n");
    }
    return 0;
}