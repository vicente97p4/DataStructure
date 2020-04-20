#include<stdio.h>
#include<stdlib.h>
#include"seqindexsearch.h"
#define FAIL 0
int sequentialSearchNotSorted(int value[], int size, int key) {
	int ret = FAIL;
	int i = 0;
	for (i = 0; i < size && value[i] != key; i++);
	if (i < size) ret = i;
	return i;
}

int sequentialSearchAsendingSorted(int value[], int size, int key) {
	int ret = FAIL;
	int i = 0;
	for (i = 0; i < size&&value[i] < key; i++);
	if (i < size && value[i] == key) ret = i;
	return ret;
}
int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key) {
	int ret = -1;
	int i = 0;
	for (i = start; i <= end && value[i] < key; i++);
	if (i <= end&&value[i] == key) ret = i;
	return ret;
}
IndexTable* createIndexTable(int value[], int size, int indexSize) {
	IndexTable* pReturn = NULL;
	int i = 0;
	int ratio = 0;

	if (size <= 0 || indexSize <= 0) {
		printf("�ε��� ũ�� �� �迭�� ũ��� 0���� Ŀ���մϴ�.\n");
		return NULL;
	}
	ratio = size / indexSize;
	if (size%indexSize > 0)
		ratio += 1;
	pReturn = (IndexTable*)malloc(sizeof(IndexTable)*indexSize);
	if (pReturn == NULL) {
		printf("����, �޸��Ҵ� in createIndexTabl()\n");
		return NULL;
	}
	for (i = 0; i < indexSize; i++) {
		pReturn[i].position = i * ratio;
		pReturn[i].key = value[i*ratio];
	}
	return pReturn;
}
int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key) {
	int ret = FAIL, i = 0, start = 0, end = 0;

	if (key >= value[0] && key <= value[size - 1]) {
		for (i = 0; i < indexSize; i++)
			if (index[i].key > key) break;
		if (i >= indexSize) {
			start = index[i - 1].position;
			end = size - 1;
		}
		else {
			start = index[i - 1].position;
			end = index[i].position - 1;
		}
		ret = sequentialRangeSearchAsendingSorted(value, start, end, key);
	}
	return ret;
}