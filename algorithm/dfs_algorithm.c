/**
깊이 우선 탐색은 맹목적 탐색방법의 하나로 한 노드를 시작으로 인접한 다른 노드를 재귀적으로 탐색해가고 끝까지 탐색하면 다시 위로 와서 다음을 탐색하여 검색한다.

위와 같은 그래프에서 숫자가 있는 원은 정점(Vertex)라고 하고, 정점과 정점을 잇는 연결선을 간선(Edge)이라고 한다. 정점의 최대 개수는 30개이다. 간선의 길이를 1이라고 하고, N개의 정점과 M개의 간선이 주어졌을 때, DFS를 이용하여 시작점으로부터 도착점까지의 최단 경로를 찾아 거리를 출력하시오. 시작점에서 도착점으로 갈 수 있는 방법이 없는 경우 -1을 출력하시오.

input
===========================
2 // test case 개수 
8 10 1 8// 정점의 수, 간선의 수, 시작점, 도착점
1 2 // 정점 간 연결 관계. 1에서 2로 이동 가능 
1 3
2 7
2 4
3 5
3 6
4 7
5 7
6 7
6 8
8 10 2 8
1 2
1 3
2 7
2 4
3 5
3 6
4 7
5 7
6 7
6 8

output
===========================
#1 3 // 최단경로의 길이 
#2 -1
**/
#include <stdio.h>

#define MAX_VERTEX 30

int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];
int vertex;
int edge;
int maxEdge;
int start;
int end;

void depthFirstSearch(int v, int depth)
{
    int i;
    if (v == end)
    {
        if (maxEdge < 0 || depth < maxEdge)
        {
            maxEdge = depth;
        }
        return;
    }

    visit[v] = 1;
    for (i=1; i <=vertex; i++)
    {
        if (map[v][i] == 1 && !visit[i])
        {
            depthFirstSearch(i, depth + 1);
            visit[i] = 0;
        }
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/dfs_algorithm_input.txt", "r", stdin);

    int T;
    int test_case;
    int i;
    int v1;
    int v2;

    scanf("%d", &T);

    for (test_case = 1; test_case <=T; test_case++)
    {
        scanf("%d %d %d %d", &vertex, &edge, &start, &end);

        for (i=0; i < edge; i++)
        {
            scanf("%d %d", &v1, &v2);
            map[v1][v2] = 1;
        }

        maxEdge = -1;
        depthFirstSearch(start, 0);
        printf("#%d %d\n", test_case, maxEdge);
    }
    return 0;
}