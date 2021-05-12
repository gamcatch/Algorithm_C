/**
Map은 키를 값에 매핑할 수 있는 자료구조로 키에 대한 중복을 허용하지 않는다. 
입력으로 주어진 N개의 command를 수행하는 프로그램을 작성하라.

Command는 1~3의 정수값을 가지며, 각각 다음과 같은 동작을 수행한다. 

1: put(key, value) // key ,value pair를 map에 추가 
2: remove(key) // key에 해당하는 요소를 삭제 
3: get(key) // key에 해당하는 요소를 출력. (만약 key에 해당하는 요소를 찾지 못했을 떄, -1을 출력 ))
**/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int key;
    int value;
    Node *left, *right;
} Node;

Node *newNode(int k, int v)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = k;
    temp->value = v;
    temp->left = temp->right = NULL;
    return temp;
}

Node *current;

Node *putRec(Node *node, int  key, int value) 
{
    if (node == NULL)
        return newNode(key, value);

    if (key < node->key)
        node->left = putRec(node->left, key, value);
    else if (key > node->key)
        node->right = putRec(node->right, key, value);
    else
        node->value = value;

    return node;
}

void put(int key, int value)
{
    current = putRec(current, key, value);
}

int findRec(Node *node, int key) 
{
    if (node != NULL) 
    {
        if (key == node->key)
            return node->value;

        int ret = -1;
        ret = findRec(node->left, key);
        if (ret != -1)
            return ret;
        ret = findRec(node->right, key);
        if (ret != -1)
            return ret;
    }

    return -1;
}

bool contains(int key)
{
    int ret = findRec(current, key);
    if (ret != -1)
        return true;
    return false;
}

int get(int key) {
    return findRec(current, key);
}

Node *minValueNode(Node *node) {
    Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *removeRec(Node *node, int key) 
{
    if (node == NULL)
        return node;

    if (key < node->key)
        node->left = removeRec(node->left, key);
    else if (key > node->key)
        node->right = removeRec(node->right, key);
    else {
        if (node->left == NULL) 
        {
            Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            Node *temp  = node->left;
            free(node);
            return temp;
        }

        Node *temp = minValueNode(node->right);
        node->key = temp->key;
        node->value = temp->value;
        node->right = removeRec(node->right, temp->key);
    }

    return node;
}

void remove(int key)
{
    current = removeRec(current, key);
}


int main(void)
{
    setbuf(stdout, NULL);
    freopen("./data_structure/map_input.txt", "r", stdin);

    int T, N;
    scanf("%d", &T);

    for (int test_case = 1; test_case <=T; test_case++)
    {
        current  = NULL;
        scanf("%d", &N);

        printf("#%d ", test_case);

        for (int i =0; i< N; ++i) 
        {
            int cmd, key, value;

            scanf("%d %d", &cmd, &key);

            switch(cmd) {
                case 1:
                    scanf("%d", &value);
                    put(key, value);
                    break;
                case 2:
                    remove(key);
                    break;
                case 3:
                    int ret = get(key);
                    printf("%d ", ret);
            }
        }

        printf("\n");
    }
    return -1;
}



