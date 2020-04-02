#include<stdio.h>
#include<stdlib.h>
#include"arrayheap.h"
void printArray(int value[], int count);

void heapSort(int value[], int count) {
	int i = 0;
	ArrayMinHeap* pHeap = NULL;

	pHeap = createArrayMaxHeap(8);
	if (pHeap != NULL) {
		HeapNode node;
		for (i = 0; i < count; i++) {
			node.key = value[i];
			insertMaxHeapAH(pHeap, node);
		}
		for (i = count-1; i >=0; i--) {
			HeapNode *pNode = deleteMaxHeapAH(pHeap);
			if (pNode != NULL) {
				value[i] = pNode->key;
				free(pNode);
			}
		}
		deleteArrayMaxHeap(pHeap);
	}
	else {
		printf("Error, createArrayMaxHeap() in heapSort()\n");
		return;
	}
}

int main(int argc, char *argv[]) {
	int value[] = { 80,50,70,10,60,20,40,30 };

	printf("Before Sort\n");
	printArray(value, 8);

	heapSort(value, 8);

	printf("\nAfter Sort\n");
	printArray(value, 8);

	return 0;
}
void printArray(int value[], int count) {
	for (int i = 0; i < count; i++) {
		printf("%d ", value[i]);
	}
	printf("\n");
}