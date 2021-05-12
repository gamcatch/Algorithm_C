/**
데이크스트라 알고리즘은 어떤 변도 음수 가중치를 갖지 않는 유향 그래프에서 주어진 출발점과 도착점 사이의 최단 경로 문제를 푸는 알고리즘이다. 
방향이 있는 그래프에서 꼭지점들을 연결하는 비용이 할당 되었을 때 임의의 꼭지점에서 다른 꼭지점으로 가는 경로들 중에서 비용이 가장 적게 드는 경로, 즉 두 정점 사이의 최단 경로를 찾아라.
입력 값 첫번째 라인에는 전체 테스트 케이스의 개수가 입력된다.
두번째 라인에는 정점의 개수, 그리고 시작 정점, 도착 정점이 입력된다. 이때, 정점의 최대 개수는 100이다.
세번째 라인에는 정점을 잇는 간선 개수(m)가 입력된다.
네번째 라인부터는 연결 된 정점 값 2개와 간선에 할당 된 비용이 m번 들어온다. 이때 간선 방향은 첫번째 입력된 정점에서 두번째 입력된 정점으로 가는 방향이다.

input
==========================
1 // test case 개수 
7 1 7 // 정점의 개수, 그리고 시작 정점, 도착 정점 
9    // 간선 개수 
1 2 4 // 1->2, 비용은 4 
1 3 2
2 4 1
2 5 2
3 4 7
3 6 3
4 7 3
5 7 1 
6 7 5

output
==========================
#1 7

**/
#include <stdio.h>

#define N 100
#define INF 100000

int map[N+1][N+1];
int visit[N+1];
int dist[N+1];
int vertex;
int edge;
int start;
int end;

void dijkstra(void)
{
    int i;
    int j;
    int min;
    int v;

    dist[start] = 0;

    for (i=1; i<=vertex ; i++)
    {
        min = INF;

        for (j=1; j<=vertex; j++) 
        {
            if (visit[j] == 0 && min > dist[j])
            {
                min = dist[j];
                v = j;
            }
        }

        visit[v] = 1;

        for (j=1; j<=vertex; j++)
        {
            if(dist[j]>dist[v] + map[v][j])
            {
                dist[j] = dist[v] + map[v][j];
            }
        }
    }
}


int main(void)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/dijkstra_input.txt", "r", stdin);
    int test_case;
    int T;
    int i;
    int j;
    int from;
    int to;
    int value;

    scanf("%d", &T);

    for (test_case = 1; test_case <=T; test_case++)
    {
        scanf("%d %d %d", &vertex, &start, &end);
        scanf("%d", &edge);

        for (i=1; i <=vertex; i++)
        {
            for (j=1; j<=vertex; j++)
            {
                if (i != j)
                {
                    map[i][j] = INF;
                }
            }
        }

        for (i = 1; i <= edge; i++)
        {
            scanf("%d %d %d", &from, &to, &value);
            map[from][to] = value;
        }

        for (i=1; i<=vertex; i++)
        {
            dist[i] = INF;
            visit[i] = 0;
        }

        printf("#%d ", test_case);
        dijkstra();
        printf("%d \n", dist[end]);
    }

    return 0;
}