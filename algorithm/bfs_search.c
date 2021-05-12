/**
너비 우선 탐색은 맹목적 탐색방법의 하나로 시작 정점을 방문한 후 시작 정점에 인접한 모든 정점들을 우선 방문하는 방법이다.

                1
               / \
             2     3
            / \   / \
           4   5 6   7
            \  \ /  /
                8

위와 같은 그래프에서 숫자가 있는 원은 정점(Vertex)라고 하고, 정점과 정점을 잇는 연결선을 간선(Edge)이라고 한다. 정점의 최대 개수는 30개이다. 정점과 정점의 연결관계가 인접행렬로 주어졌을 때, BFS를 이용하여 시작 정점으로부터 모든 정점을 탐색한 결과를 순서대로 화면에 출력하시오.

input
===================================
1 //test case 개수
8 1 // 정점의 개수, 시작 정점
1 2 // 정점 간 연결 관계. 1과 2가 연결
1 3
2 4
2 5
4 8
5 8
3 6
3 7
6 8
7 8
-1 -1 // 입력 끝

output
====================================
#1 1 2 3 4 5 6 7 8  // 방문한 정점 순서
**/
#include <stdio.h>

#define MAX_VERTEX 30

int vertex;
int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];
int queue[MAX_VERTEX];
int rear, front;

void breadthFirstSearch(int v)
{
    int i;
    visit[v] = 1;
    printf("%d ", v);
    queue[rear++] = v;
    while(front < rear)
    {
        v = queue[front++];
        for (i = 1; i <= vertex; i++)
        {
            if (map[v][i] == 1 && !visit[i])
            {
                visit[i] = 1;
                printf("%d ", i);
                queue[rear++] = i;
            }
        }
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/bfs_search_input.txt", "r", stdin);

    int T;
    int test_case;
    int i, j;
    int start;
    int v1;
    int v2;

    scanf("%d", &T);

    for (test_case = 1; test_case <= T; test_case++)
    {
        for (i =0; i < MAX_VERTEX; i++)
        {
            for (j = 0; j < MAX_VERTEX; j++)
            {
                map[i][j] = 0;
            }
            visit[i] = 0;
        }

        scanf("%d %d", &vertex, &start);

        while (true)
        {
            scanf("%d %d", &v1, &v2);
            if (v1 == -1 && v2 == -1)
            {
                break;
            }
            map[v1][v2] = map[v2][v1] = 1;
        }

        printf("#%d ", test_case);
        breadthFirstSearch(start);
        printf("\n");
    }
    return 0;
}