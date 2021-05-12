#include <stdio.h>
#include <stdlib.h>

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)

// trie node 
typedef struct trie_node trie_node_t;
struct trie_node{
	int value;
	trie_node_t * children[ALPHABET_SIZE];
};

// trie
typedef struct trie trie_t;
struct trie{
	trie_node_t * root;
	int count;
};

trie_node_t *getNode(void)
{
	trie_node_t *pNode = NULL;

	pNode = (trie_node_t *)malloc(sizeof(trie_node_t));

	if (pNode)
	{
		int i;
		pNode->value = 0;

		for (i = 0; i < ALPHABET_SIZE; ++i) {
			pNode->children[i] = NULL;
		}
	}

	return pNode;
}

// init trie
void initialize(trie_t *pTrie)
{
	pTrie->root = getNode();
	pTrie->count = 0;
}

int strlen(const char str[])
{
	int L = ARRAY_SIZE(str);
	int i;
	for (i = 0; i < L; ++i) {
		if (str[i] == '\0') break;
	}

	return i;
}

void insert(trie_t *pTrie, char key[])
{
	int level;
	int length = strlen(key);
	int index;
	trie_node_t *pCrawl;

	pTrie->count++;
	pCrawl = pTrie->root;
	for (level = 0; level < length; level++) {
		index = CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index]) {
			pCrawl->children[index] = getNode();
		}

		pCrawl = pCrawl->children[index];
	}

	// 들어온 key 값의 마지막 단에에는 끝이라는 표시를 위해 
	pCrawl->value = pTrie->count;
}

// return 0 if not found
int search(trie_t *pTrie, const char key[]) {
	int level;
	int length = strlen(key);
	int index;
	trie_node_t *pCrawl;

	pCrawl = pTrie->root;

	for (level = 0; level < length; level++) {
		index = CHAR_TO_INDEX(key[level]);

		if (!pCrawl->children[index]) {
			return 0; // Not found
		}

		pCrawl = pCrawl->children[index];
	}

	return (0 != pCrawl && pCrawl->value);
}

int main()
{
	char keys[][8] = { "the", "a", "there", "answer" , "any", "by", "bye", "their"};

	trie_t trie;

	char output[][32] = { "Not present in trie", "Present in trie" };

	// trie initialization
	initialize(&trie);

	// construct trie data structure
	for (int i = 0; i < ARRAY_SIZE(keys); i++) {
		insert(&trie, keys[i]);
	}

	// search and print result
	printf("%s --- %s\n", "the", output[search(&trie, "the")]);
	printf("%s --- %s\n", "these", output[search(&trie, "these")]);
	printf("%s --- %s\n", "their", output[search(&trie, "their")]);
	printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")]);

	return 0;
}
