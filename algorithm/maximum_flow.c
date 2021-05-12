/**
Network flow란 각각의 간선에 정해진 용량보다 작은 유량이 주어진 방향그래프를 말하며,
Maximum flow란 위 수원지(S)에서 수요지(T)까지 공급할 수 있는 최대 유량을 말한다.
V (2<= V <=10)개의 정점과 E (2<= E <=20)개의 간선이 용량을 갖는 그래프에서 두 정점 사이에 얼마나 많은 유량을 보낼 수 있는지를 계산하여 출력하시오, 각 간선의 유량은 해당 간선의 용량을 초과할 수 없다.
첫 라인은 테스트 케이스 수, 두번째 라인은 수원지, 수요지를 포함한 정점의 수와 그를 연결하는 방향성을 띈 간선의 수가 입력되며, 다음 라인 부터는 간선의 정보가 입력된다
간선의 정보는 출발지, 도착지, 용량 순이다.

input
========================================
2 // 테스트 케이스 수
6 10 // 정점, 간선의 수
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
6 7
0 1 10
0 3 8
1 2 10
1 4 6
2 5 10
3 2 8
4 5 6

output
========================================
#1 23
#2 16

**/
#include <stdio.h>

#define MAX_V 10
const int INF = 987654321;
int V;

typedef struct {
    int queueArray[MAX_V];
    int front;
    int rear;
} Queue;

void push(Queue *q, int item)
{
    if ((q->rear + 1) % MAX_V == q->front)
    {
        return;
    }
    q->queueArray[q->rear] = item;
    q->rear = (q->rear + 1) % MAX_V;
}

void pop(Queue *q)
{
    if (q->front == q->rear)
    {
        return ;
    }
    q->front = (q->front + 1) % MAX_V;
}

int getFront(Queue *q)
{
    return q->queueArray[q->front];
}

int isEmpty(Queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int networkFlow(int source, int sink, int capacity[][MAX_V])
{
    int flow[MAX_V][MAX_V] = {0, };
    int parent[MAX_V];
    int totalFlow = 0;
    int p;
    while (1)
    {
        for (p=0; p < V; p++)
        {
            parent[p] = -1;
        }

        Queue q;

        q.front = 0;
        q.rear = 0;

        parent[source] = source;
        push(&q, source);

        while (!isEmpty(&q))
        {
            int here = getFront(&q);
            pop(&q);
            int there;
            for (there =0; there < V; ++there)
            {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    push(&q, there);
                    parent[there] = here;
                }
            }
        }
        if (parent[sink] == -1)
        {
            break;
        }

        int amount = INF;
        for (p = sink; p != source ; p=parent[p])
        {
            if (capacity[parent[p]][p] - flow[parent[p]][p] > amount)
            {
                amount = amount;
            }
            else {
                amount = capacity[parent[p]][p] - flow[parent[p]][p];
            }
        }

        for (p = sink; p != source; p=parent[p])
        {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;

    }
    return totalFlow;
}

int main(int argc, char** argv)
{
    int T;
    setbuf(stdout, NULL);
    freopen("./algorithm/maximum_flow_input.txt", "r", stdin);

    scanf("%d", &T);

    for (int test_case = 1; test_case <=T; ++test_case)
    {
        int capacity[MAX_V][MAX_V] = {0, };
        int E, here, there, C, answer;

        scanf("%d %d", &V, &E);
        for (int i = 0; i < E; i++)
        {
            scanf("%d %d %d", &here, &there, &C);
            capacity[here][there] = C;
        }
        answer = networkFlow(0, V-1, capacity);

        printf("#%d %d\n", test_case, answer);
    }

    return 0;
}