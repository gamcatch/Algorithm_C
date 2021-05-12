/**
그래프의 최대 이분 매칭은 두 간선이 같은 정점을 공유하지 않는 간선의 최대 집합을 말한다.
A그룹과 B그룹이 있다. 각각의 그룹에는 1부터 시작하는 n명의 멤버들이 있으며, 서로 다른 그룹의 멤버들을 연결하는 선이 존재한다. 이 때, 서로 다른 그룹의 멤버끼리 2명씩 짝을 지을 때, 가능한 최대 짝의 수를 출력하시오.

input
======================================
2 // test case 수
3 // A그룹 멤버 수
2 // B그룹 멤버 수
3 // 연결 선의 수
1 1 // A그룹1과 B그룹1 연결
2 2 // A그룹2와 B그룹2 연결
3 2 // A그룹3과 B그룹2 연결
4
5
8
1 1
1 2
1 3
2 2
2 3
2 4
3 3
4 5


output
=======================================
#1 2 // 가능한 최대 짝의 수
#2 4

**/
#include <stdio.h>

#define MAX 1000

int countA, countB;
int matchA[MAX];
int matchB[MAX];
int adj[MAX][MAX];
int visited[MAX];

int dfs(int a)
{
    int b;

    if (visited[a])
    {
        return 0;
    }

    visited[a] = 1;

    for (b=0; b<countB; ++b)
    {
        if (adj[a][b] && (matchB[b] == -1 || dfs(matchB[b])))
        {
            matchA[a] = b;
            matchB[b] = a;
            return 1;
        }
    }

    return 0;
}

int bipartiteMatch(void)
{
    int size=0;
    int start;
    int i;

    for (start = 0; start < countA; ++start)
    {
        for (i=0; i < countA; i++)
        {
            visited[i] = 0;
        }
        if (dfs(start))
        {
            size ++;
        }
    }
    return size;
}


void initialize(void)
{
    int i, j;
    for (i=0; i < countA; i++)
    {
        matchA[i] = -1;
        for (j=0; j < countB; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (i=0; i < countB; i++)
    {
        matchB[i] = -1;
    }
}

int main(int argc, char * argv[])
{
    setbuf(stdout, NULL);
    freopen("./algorithm/bipartite_match_input.txt", "r", stdin);

    int T, adjCount;

    scanf("%d", &T);

    for (int test_case = 1; test_case  <= T; test_case++)
    {
        scanf("%d", &countA);
        scanf("%d", &countB);

        initialize();

        scanf("%d", &adjCount);

        for (int i =0; i < adjCount; i++)
        {
            int a, b;
            scanf("%d", &a);
            scanf("%d", &b);
            adj[a-1][b-1] = 1;
        }
        printf("#%d %d\n", test_case, bipartiteMatch());
    }
    return 0;
}