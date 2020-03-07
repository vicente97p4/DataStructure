#include<stdio.h>
#include<stdlib.h>
#include"arrayqueue.h"

void displayArrayQueue(ArrayQueue *pQueue) {
	int i = 0;
	if (pQueue != NULL) {
		printf("ť�� ũ��: %d, ���� ��� ����: %d\n", pQueue->maxElementCount, pQueue->currentElementCount);

		for (i = pQueue->front + 1; i <= pQueue->rear; i++)
			printf("[%d]-[%c]\n", i, pQueue->pElement[i].data);
	}
}

int enqueueAQChar(ArrayQueue* pQueue, char data) {
	ArrayQueueNode node = { 0, };
	node.data = data;
	return enqueueAQ(pQueue, node);
}

int main() {
	ArrayQueue *pQueue = NULL;
	ArrayQueueNode *pNode = NULL;
	char value = 0;

	pQueue = createArrayQueue(4);
	if (pQueue != NULL) {
		enqueueAQChar(pQueue, 'A');
		enqueueAQChar(pQueue, 'B');
		enqueueAQChar(pQueue, 'C');
		enqueueAQChar(pQueue, 'D');
		displayArrayQueue(pQueue);

		pNode = dequeueAQ(pQueue);
		if (pNode != NULL) {
			printf("Dequeue Value-[%c]\n", pNode->data);
			free(pNode);
		}
		displayArrayQueue(pQueue);

		pNode = peekAQ(pQueue);
		if (pNode != NULL) {
			printf("Peek Value-[%c]\n", pNode->data);
		}
		displayArrayQueue(pQueue);
		enqueueAQChar(pQueue, 'E');
		displayArrayQueue(pQueue);
	}
	return 0;
}