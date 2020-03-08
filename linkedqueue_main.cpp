#include<stdio.h>
#include<stdlib.h>
#include"linkedqueue.h"

void displayLinkedQueue(LinkedQueue *pQueue) {
	QueueNode *pNode = NULL;
	int i = 0;
	if (pQueue != NULL) {
		printf("���� ��� ����: %d\n", pQueue->currentElementCount);
		pNode = pQueue->pFrontNode;
		while (pNode != NULL) {
			printf("[%d]-[%c]\n", i, pNode->data);
			i++;
			pNode = pNode->pLink;
		}
	}
}