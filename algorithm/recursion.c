/**
재귀는 수학이나 컴퓨터 과학 등에서 자신을 정의할 때 자기 자신을 재참조하는 방법을 뜻한다. 주로 이 방법은 함수에 적용한 재귀 함수(Recursion Function)의 형태로 많이 사용된다.
주어진 수의 Factorial 값을 구해 아래와 같이 출력하시오. 주어지는 수는 1 이상 20 이하의 수이다.

input 
=======================
3 // 전체 Test case 수 
9 // Test case index 
12
20

output 
=======================
#1 9! = 362880
#2 12! = 479001600
#3 20! = 2432902008176640000

**/

#include <stdio.h>

long long factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num-1);
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    freopen("./algorithm/recursion_input.txt", "r", stdin);

    int test_case;
    int T;
    int num;
    long long value;

    scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d", &num);
        value = factorial(num);
        printf("#%d %d! = %lld\n", test_case, num, value);
    }

}