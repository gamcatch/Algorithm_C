/**
Queue는 컴퓨터의 기본적인 자료 구조의 한가지로, 먼저 집어 넣은 데이터가 먼저 나오는 FIFO (First In First Out)구조로 저장하는 형식을 말한다. 
주어진 N(2<= N <=100)개의 수를 순서대로 Queue에 넣은 후 하나씩 꺼내 화면에 출력하시오.

input  
===============================
2 // 테스트 케이스 수 
5 // 데이터 크기 
1 2 3 4 5
5
5 4 2 3 1

output 
================================
#1 1 2 3 4 5 
#2 5 4 2 3 1

**/
#include <stdio.h>

#define MAX_N 100

int front;
int rear;
int queue[MAX_N];

void queueInit(void)
{
  front = 0;
  rear = 0;
}

int queueIsEmpty(void)
{
  return (front == rear);
}

int queueIsFull(void)
{
  if ((front + 1)%MAX_N == rear)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}

int queueEnqueue(int value)
{
  if (queueIsFull())
  {
    printf("queue is full!");
    return 0;
  }
  queue[front] = value;
  front++;
  if (front == MAX_N) {
    front = 0;
  }

  return 1;
}

int queueDequeue(int *value) 
{
  if (queueIsEmpty()) {
    printf("queue is empty!");
    return 0;
  }
  *value = queue[rear];
  rear++;
  if (rear == MAX_N)
  {
    rear = 0;
  }

  return 1;
}

int main(int argc, char* argv[]) 
{
  setbuf(stdout, NULL);
  freopen("./data_structure/queue_input.txt", "r", stdin);

  int T, N;

  scanf("%d", &T);

  for (int test_case = 1; test_case<=T; test_case++)
  {
    scanf("%d", &N);

    queueInit();
    for (int i = 0; i < N; i++) {
      int value;
      scanf("%d", &value);
      queueEnqueue(value);
    }

    printf("#%d ", test_case);

    while (!queueIsEmpty()) {
      int value;
      if (queueDequeue(&value) == 1)
      {
        printf("%d ", value);
      }
    }
    printf("\n");
  }
  return 0;
}
