#include <stdio.h>

// Array
/**
int arr_idx = 0;

struct NODE {
	int v;
} arr[10000];

NODE* myalloc(void) {
	return &arr[arr_idx++];
}
**/

// Single Linked List
int arr_idx = 0;

struct NODE {
	int v;
	NODE* prev;  // single linked list
} arr[10000];

NODE* myalloc(void) {
	return &arr[arr_idx++];
}

int main(void) {
	NODE* pList = NULL; // 싱글 링크드리스트의 시작 
	NODE* p;

	arr_idx = 0; // 배열 초기화

	// add node(1)
	p = myalloc();
	p->v = 1;
	p->prev = pList;
	pList = p;

	// add node(2)
	p = myalloc();
	p->v = 2;
	p->prev = pList;
	pList = p;

	// display
	for (NODE* pp = pList; pp != NULL; pp = pp->prev)
	{
		printf("%d ", pp->v);
	}

    printf("\n");

	return 0;
}
