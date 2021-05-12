/**

Set 은 집합을 정의하며 요소의 중복을 허용하지 않는 자료구조이다.
입력으로 주어진 N개의 Command 를 수행한 후
Set 에 있는 모든 원소를 오름차순으로 출력하라.

1 : add
2 : remove

Input
=====================================
1 
11
1 50
1 30
1 40
1 70
1 60
1 80
2 20
2 30
2 50
1 10

output 
======================================
#1 10 40 60 70 80

**/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int key;
    Node *left, *right;
} Node;

Node *newNode(int item) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *current;

Node *addRec(Node *node, int key) 
{
    if (node == NULL) 
        return newNode(key);

    if (key < node->key)
        node->left = addRec(node->left, key);
    else if (key > node->key)
        node->right = addRec(node->right, key);

    return node;
}

void add(int key) {
    current = addRec(current, key);
}

bool findRec(Node *node, int key) {
    if (node != NULL) {
        if (key == node->key)
            return true;
        if (findRec(node->left, key)) 
            return true;
        if (findRec(node->right, key))
            return true;
    }

    return false;
}


bool contains(int key) 
{
    return findRec(current , key);
}

void printAll(Node *node) 
{
    if (node != NULL) 
    {
        printAll(node->left);
        printf("%d ", node->key);
        printAll(node->right);
    }

}

void printAll() 
{
    printAll(current);
}

Node *minValueNode(Node *node) 
{
    Node *current = node;

    while(current->left != NULL)
        current  = current->left;

    return current;
}

Node *removeRec(Node *node, int key) {
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
            Node *temp = node->left;
            free(node);
            return temp;
        }

        Node* temp = minValueNode(node->right);
        node->key = temp->key;
        node->right = removeRec(node->right, temp->key);
    }
    return node;
}

void remove(int key) {
    current = removeRec(current, key);
}

int main(void) 
{
    setbuf(stdout, NULL);

    freopen("./data_structure/set_input.txt", "r", stdin);

    int T, N;
    scanf("%d", &T);

    for (int test_case = 1; test_case <=T; test_case++)
    {
        current = NULL;
        scanf("%d", &N);

        for (int i=0; i < N; i++)
        {
            int cmd, key;

            scanf("%d %d", &cmd, &key);

            switch(cmd)
            {
                case 1:
                    add(key);
                    break;
                case 2:
                    remove(key);
                    break;
                
            }
        }

        printf("#%d ", test_case);

        printAll();
        printf("\n");
    }
}