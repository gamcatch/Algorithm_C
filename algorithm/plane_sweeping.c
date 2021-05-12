/**
Plane sweeping은 여러 개의 직사각형이 주어졌을 때, 총 넓이를 구하는 알고리즘이다.
 테스트케이스 수 T와 지도의 수 N(1 ≤ N ≤ 10,000)이 주어진다. 다음 N개의 줄에는 각 지도의 정보가 주어진다. 지도의 정보는 네 정수 x1, y1, x2, y2 (0 ≤ x1 < x2 ≤ 30,000, 0 ≤ y1 < y2 ≤ 30,000)으로 이루어져 있다. (x1, y1)와 (x2, y2)은 직사각형의 왼쪽 아래 좌표와 오른쪽 위 좌표이다. 모든 지도는 직사각형이고, 변은 항상 x축 또는 y축에 평행하다. 첫째 줄에 지도를 모두 합쳤을 때, 그 면적을 출력한다. (직사각형을 모두 합쳤을 때 면적)

 input 
 =============================
1   // T, # of testcases 
2   // N, # of given maps 
10 10 20 20
15 15 25 30

 output
 =============================
#1 225
**/

#include <stdio.h>

int N;
#define MAX_N 10000

typedef struct rec
{
    int x, y1, y2, end;
} rec;

rec make_rec(int _x, int _y1, int _y2, int _end)
{
    rec t = {_x, _y1, _y2, _end};
    return t;
}

int rec_greater_than(rec* a, rec* b)
{
    return a->x != b->x ? a->x > b->x : 0;
}

int tree[65538], cnt[65538];

void update(int x, int left, int right, int nodeLeft, int nodeRight, int val)
{
    if (left > nodeRight || right < nodeLeft)
    {
        return;
    }

    if (left <= nodeLeft && right >= nodeRight) 
    {
        cnt[x] += val;
    }
    else
    {
        int mid = (nodeLeft + nodeRight) >> 1;
        update(x*2, left, right, nodeLeft, mid, val);
        update(x*2 + 1, left, right, mid + 1, nodeRight, val);
    }

    tree[x] = 0;
    if (cnt[x] > 0)
    {
        tree[x] = nodeRight - nodeLeft + 1;
    }
    if (cnt[x] ==0 && nodeLeft < nodeRight)
    {
        tree[x] = tree[x * 2] + tree[x*2 + 1];
    }
}

int partition(rec a[], int l, int r)
{
    rec pivot, t;
    int i, j;
    pivot = a[l];
    i = l;
    j = r + 1;

    while (1) {
        do {
            ++i;
        } while ((!rec_greater_than(&a[i], &pivot)) && i <= r);

        do {
            --j;
        } while (rec_greater_than(&a[j], &pivot));

        if (i >= j)
        {
            break;
        }
        t= a[i];
        a[i] = a[j];
        a[j] = t;
    }

    t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}

void quick_sort(rec a[], int l, int r)
{
    int j;

    if (l < r)
    {
        j = partition(a, l, r);
        quick_sort(a, l, j -1);
        quick_sort(a, j+1, r);
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/plane_sweeping_input.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for (int test_case = 1; test_case <=T; test_case++)
    {
        static rec v[MAX_N * 2];
        scanf("%d", &N);

        int idx = 0, i, px, ans;
        for (i=0; i <N; i++)
        {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            v[idx++] = make_rec(x1, y1, y2, 1);
            v[idx++] = make_rec(x2, y1, y2, -1);
        }

        quick_sort(v, 0, idx - 1);
        px = v[0].x;
        ans = 0;
        for (i = 0; i < idx; i++)
        {
            ans += (v[i].x -px ) * tree[1];
            update(1, v[i].y1, v[i].y2-1, 0, 32768, v[i].end);
            px = v[i].x;
        }
        printf("#%d ", test_case);
        printf("%d\n", ans);
    }

    return 0;
}