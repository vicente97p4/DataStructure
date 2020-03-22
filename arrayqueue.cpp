#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount) {
	ArrayQueue* pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = (ArrayQueue*)malloc(sizeof(ArrayQueue));
		if (pReturn != NULL) {
			memset(pReturn, 0, sizeof(ArrayQueue));
			pReturn->maxElementCount = maxElementCount;
			pReturn->front = -1;
			pReturn->rear = -1;
		}
		else {
			printf("����, �޸��Ҵ�, createArrayQueue()\n");
			return NULL;
		}
	}
	else {
		printf("����, ť ũ��� 0���� Ŀ�� �մϴ�.\n");
		return NULL;
	}
	pReturn->pElement = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode)*maxElementCount);

	if (pReturn->pElement != NULL) memset(pReturn->pElement, 0, sizeof(ArrayQueueNode)*maxElementCount);
	else {
		printf("����, �޸� �Ҵ�2, createArrayQueue()\n");
		free(pReturn);
		return NULL;
	}
	return pReturn;
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element) {
	int ret = FALSE;
	int i = 0;

	if (pQueue != NULL) {
		if (isArrayQueueFull(pQueue) == FALSE) {
			pQueue->rear++;
			pQueue->pElement[pQueue->rear] = element;
			pQueue->currentElementCount++;
			ret = TRUE;
		}
		else printf("����, ť�� ���� á���ϴ�.\n");
	}
	return ret;
}

ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue) {
	ArrayQueueNode *pReturn = NULL;
	if (pQueue != NULL) {
		if (isArrayQueueEmpty(pQueue) == FALSE) {
			pReturn=(ArrayQueueNode*)malloc(sizeof(ArrayQueueNode));
			if (pReturn != NULL) {
				pQueue->front++;
				pReturn->data = pQueue->pElement[pQueue->front].data;
				pQueue->currentElementCount--;
			}
			else printf("����, �޸��Ҵ�, dequeueAQ()\n");
		}
	}
	return pReturn;
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue) {
	ArrayQueueNode *pReturn = NULL;
	if (pQueue != NULL) {
		if (isArrayQueueEmpty(pQueue) == FALSE) {
			pReturn = &(pQueue->pElement[pQueue->front + 1]);
		}
	}
	return pReturn;
}

void deleteArrayQueue(ArrayQueue* pQueue) {
	if (pQueue != NULL) {
		if (pQueue->pElement != NULL)
			free(pQueue->pElement);
		free(pQueue);
	}
}

int isArrayQueueFull(ArrayQueue* pQueue) {
	int ret = FALSE;

	if (pQueue != NULL) {
		if (pQueue->currentElementCount == pQueue->maxElementCount || pQueue->rear == pQueue->maxElementCount - 1) {
			ret = TRUE;
		}
	}
	return ret;
}

int isArrayQueueEmpty(ArrayQueue* pQueue) {
	int ret = FALSE;

	if (pQueue != NULL)
		if (pQueue->currentElementCount == 0)
			ret = TRUE;
	return ret;
}