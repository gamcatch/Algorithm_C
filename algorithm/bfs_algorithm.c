/**
너비 우선 탐색은 맹목적 탐색방법의 하나로 시작 정점을 방문한 후 시작 정점에 인접한 모든 정점들을 우선 방문하는 방법이다. 
0과 1로 이뤄진 지도에서 상하좌우 만으로 이동이 가능할 때, 좌상단(1, 1)에서 우하단(R, C)까지 최단 거리를 구하시오. 이때, 범위 외의 지역은 벽으로 가정하고, 1로 표시된 곳으로만 이동이 가능하다. 지도의 크기는 R, C로 주어지며, 그 범위는 1 <= R, C <= 50로 한정한다.

input
=====================
2  // test case 개수 
4 5 // R, C 
1 1 1 1 0  // MAP, 
1 0 1 0 0  // 0: 벽 
1 1 0 0 1  // 1: 길 
0 1 1 1 1  // 테두리는 벽으로 가정 
10 10
1 1 1 1 1 1 0 1 1 1
1 0 0 0 0 1 0 1 0 1
1 0 0 0 0 1 1 1 0 1
1 0 0 1 1 1 0 0 0 1
1 0 0 1 0 1 0 1 1 1
1 0 0 1 0 1 1 1 0 1
1 0 0 1 0 0 1 0 0 1
1 1 0 1 1 1 0 0 0 1
 0 1 0 1 0 1 1 1 0 1 
0 1 1 1 0 0 1 1 1 1

output
=====================
#1 7
#2 20
**/
#include <stdio.h>

#define MAX_N 50

int MAP[MAX_N + 2][MAX_N + 2];
int queue[MAX_N * MAX_N][3];
int row;
int column;
int head;
int rear;

int isEmpty()
{
    return (head <= rear) ? 1 : 0;
}

int enqueue(int x, int y, int  c)
{
    queue[head][0] = x;
    queue[head][1] = y;
    queue[head][2] = c;
    head++;
    return 1;
}

int dequeue(int *x, int *y, int *c)
{
    if (isEmpty())
    {
        return 0;
    }
    *x = queue[rear][0];
    *y = queue[rear][1];
    *c = queue[rear][2];

    rear++;
    return 1;
}

int breadthFirstSearch()
{
    int x;
    int y;
    int c;

    enqueue(1, 1, 0);
    MAP[1][1] = 0;
    while (!isEmpty())
    {
        dequeue(&x, &y, &c);
        if (x == column && y == row)
        {
            return c;
        }
        if (x + 1 <= column && MAP[x+1][y])
        {
            enqueue(x + 1, y, c+1);
            MAP[x+1][y] = 0;
        }
        if (y + 1 <= row && MAP[x][y+1])
        {
            enqueue(x, y+1, c+ 1);
            MAP[x][y+1] = 0;
        }
        if (x - 1 > 0 && MAP[x-1][y])
        {
            enqueue(x-1, y, c+1);
            MAP[x-1][y] = 0;
        }
        if (y - 1 > 0 && MAP[x][y-1])
        {
            enqueue(x, y - 1, c+1);
            MAP[x][y-1] = 0;
        }
    }

    return -1;
}

int main(void)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/bfs_algorithm_input.txt", "r", stdin);

    int test_case;
    int T;

    scanf("%d", &T);

    for (test_case = 1; test_case <=T; test_case++)
    {
        head = 0;
        rear = 0;
        scanf("%d %d", &row, &column);

        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= column ; j++)
            {
                scanf("%d", &MAP[j][i]);
            }
        }
        printf("#%d %d\n", test_case, breadthFirstSearch());
    }

    return 0;
}