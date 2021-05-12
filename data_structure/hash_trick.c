#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

#define MAX_TABLE 100

unsigned long myhash(const char* str) {
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

struct NODE {
	char data[7];

	NODE* prev;
} arr[10000];

NODE* hTable[MAX_TABLE];

int arr_idx = 0;

NODE* myalloc() {
	return &arr[arr_idx++];
}

int main(void) {
	int key;
	char in[7] = "aaaaaa";

	key = (int)myhash(in);

	NODE* p = NULL;
	p = myalloc();
	strncpy(p->data, in, 7);
	p->prev = hTable[key];
	hTable[key] = p;

	char in2[7] = "vrvipy";
	key = (int)myhash(in2);
	p = myalloc();
	strncpy(p->data, in2, 7);
	p->prev = hTable[key];
	hTable[key] = p;

	char search[7] = "vrvipy";

	int k = (int)myhash(search);

	for (NODE* pp = hTable[k]; pp != NULL; pp = pp->prev) {
		if (!strncmp(search, pp->data, 6)) {
			printf("FOUND %s\n", pp->data);
		}
	}

	// delete
	k = (int)myhash(search);
	NODE** del = &hTable[k];

	for (NODE* iter = hTable[k]; iter != nullptr; iter = iter->prev) {
		if (!strncmp(search, iter->data, 6)) {
			printf("FOUND %s\n", iter->data);

			*del = iter->prev;
		}
		del = &iter->prev;
	}
	return 0;
}