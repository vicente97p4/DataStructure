#include<stdio.h>
#include<stdlib.h>
#include"graphtraversal.h"
#include"linkedstack.h"

int pushLSForDFS(LinkedStack* pStack, int nodeID) {
	StackNode node = { 0, };
	node.data = nodeID;
	return pushLS(pStack, node);
}

void traversalDFS(LinkedGraph* pGraph, int startVertexID) {
	int i = 0;
	int vertexID = 0;
	LinkedStack* pStack = NULL;
	StackNode* pStackNode = NULL;
	ListNode *pListNode = NULL;
	int *pVisited = NULL;

	if (pGraph == NULL) return;
	pStack = createLinkedStack();
	if (pStack == NULL) return;
	pVisited = (int*)malloc(sizeof(int)*pGraph->maxVertexCount);
	if (pVisited == NULL) {
		printf("오류, 메모리할당 in traversalDFS()\n");
		return;
	}

	for (i = 0; i < pGraph->maxVertexCount; i++)
		pVisited[i] = FALSE;
	pVisited[startVertexID] = TRUE;
	pushLSForDFS(pStack, startVertexID);

	while (isLinkedStackEmpty(pStack) == FALSE) {
		pStackNode = popLS(pStack);
		if (pStackNode != NULL) {
			vertexID = pStackNode->data;
			printf("[%d]-방문\n", vertexID);

			pListNode = pGraph->ppAdjEdge[vertexID]->headerNode.pLink;
			while (pListNode != NULL) {
				int vertexID = pListNode->data.vertexID;
				if (pVisited[vertexID] == FALSE) {
					pVisited[vertexID] = TRUE;
					pushLSForDFS(pStack, vertexID);
				}
				pListNode = pListNode->pLink;
			}
		}
	}
	free(pVisited);
	deleteLinkedStack(pStack);
}

int enqueueLQForBFS(LinkedQueue* pQueue, int nodeID) {
	QueueNode node = { 0, };
	node.data = nodeID;
	return enqueueLQ(pQueue, node);
}

void traversalBFS(LinkedGraph* pGraph, int startVertexID) {
	int i = 0;
	int vertexID = 0;
	QueueNode *pTop = NULL;
	LinkedQueue* pQueue = NULL;
	QueueNode* pQueueNode = NULL;
	ListNode *pListNode = NULL;

	int *pVisited = NULL;

	if (pGraph == NULL) return;

	pQueue = createLinkedQueue();
	if (pQueue == NULL) return;

	pVisited = (int*)malloc(sizeof(int)*pGraph->maxVertexCount);

	if (pVisited == NULL) {
		printf("Error, malloc() in traversalDFS()\n");
		return;
	}

	for (i = 0; i < pGraph->maxVertexCount; i++)
		pVisited[i] = FALSE;
	pVisited[startVertexID] = TRUE;
	enqueueLQForBFS(pQueue, startVertexID);

	while (isLinkedQueueEmpty(pQueue) == FALSE) {
		pQueueNode = dequeueLQ(pQueue);
		if (pQueueNode != NULL) {
			vertexID = pQueueNode->data;
			printf("[%d]-visited\n", vertexID);

			pListNode = pGraph->ppAdjEdge[vertexID]->headerNode.pLink;
			while (pListNode != NULL) {
				int vertexID = pListNode->data.vertexID;
				if (pVisited[vertexID] == FALSE) {
					pVisited[vertexID] = TRUE;
					enqueueLQForBFS(pQueue, vertexID);
				}
				pListNode = pListNode->pLink;
			}
		}
	}
	free(pVisited);
	deleteLinkedQueue(pQueue);
}