/**
parametric search는 어떤 알고리즘으로 해를 바로 구해내는 것이 아니고, 임의의 값을 던지고 맞는지 확인해가며 해를 구하는 방법이다. 
길이가 각각 다른 K개의 리본을 가지고 있다. 공예작품을 만들기 위해 가지고 있는 리본을 잘라서 길이가 동일한 N개의 리본재료를 만들려고 한다. 리본재료의 최대 길이를 구하시오
( 1 <= K <= 10,000;  1 <= N <= 1,000,000; K <= N )
- 손실되는 길이는 없음
- 만들 수 없는 경우는 없다
- 이미 자른 리본은 붙일 수 없다
- 자를 때는 정수 cm 단위로 자른다

input
===========================
1 // test case 개수
4    // 가지고 있는 리본의 개수 K 
11   // 필요한 리본재료의 개수 N 
802
743
457
539


output
===========================
#1 200

**/
#include <stdio.h>

#define MAX_RIBBON 100

int K;
int N;
int low, high, mid, numRibbonTape, max;
int sizeRibbonTape[MAX_RIBBON];

void search()
{
    mid = low + (high - low) / 2;
    numRibbonTape = 0;

    for (int i = 0; i < K; i++)
    {
        numRibbonTape += (sizeRibbonTape[i] / mid);
    }

    if (numRibbonTape >= N)
    {
        low = mid + 1;
        if (max < mid)
            max = mid;
    }
    else 
    {
        high = mid - 1;
    }
}

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/parametric_search_input.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++)
    {
        low = 1;
        high = 0;
        max = -1;

        scanf("%d %d", &K, &N);

        for (int i = 0; i < K; i++)
        {
            scanf("%d", &sizeRibbonTape[i]);

            if (high < sizeRibbonTape[i])
            {
                high = sizeRibbonTape[i];
            }
        }

        while (low <= high)
        {
            search();
        }

        printf("#%d ", test_case);
        printf("%d\n", max);
    }
    return 0;
}