#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedgraph.h"

LinkedGraph* createLinkedGraph(int maxVertexCount) {
	int i = 0, j = 0;
	LinkedGraph *pReturn = NULL;

	if (maxVertexCount > 0) {
		pReturn = (LinkedGraph*)malloc(sizeof(LinkedGraph));
		if (pReturn == NULL) {
			printf("오류, 메모리할당(1), in createLinkedGraph()\n");
			return NULL;
		}
		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
		pReturn->currentEdgeCount = 0;
		pReturn->currentVertexCount = 0;
	}
	else {
		printf("오류, 최대 노드 개수는 0보다 커야합니다.\n");
		return NULL;
	}
	pReturn->pVertex = (int*)malloc(sizeof(int)*maxVertexCount);
	if (pReturn->pVertex == NULL) {
		printf("오류, 메모리할당(2), in createArrayGraph()\n");
		return NULL;
	}
	memset(pReturn->pVertex, NOT_USED, sizeof(int)*maxVertexCount);

	pReturn->ppAdjEdge = (LinkedList**)malloc(sizeof(LinkedList*)*maxVertexCount);

	if(pReturn->ppAdjEdge == NULL) {
		printf("오류, 메모리할당(3), in createLinkedGraph()\n");
		return NULL;
	}
	for (i = 0; i < maxVertexCount; i++) {
		pReturn->ppAdjEdge[i] = createLinkedList();
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("오류, 메모리할당(4), in createLinkedGraph()\n");
			return NULL;
		}
	}
	return pReturn;
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount) {
	LinkedGraph* pReturn = NULL;

	pReturn = createLinkedGraph(maxVertexCount);
	if (pReturn != NULL) pReturn->graphType = GRAPH_DIRECTED;

	return pReturn;
}

int addVertexLG(LinkedGraph* pGraph, int vertexID) {
	int ret = SUCCESS;

	if (pGraph != NULL) {
		if (vertexID < pGraph->maxVertexCount) {
			if (pGraph->pVertex[vertexID] == NOT_USED) {
				pGraph->pVertex[vertexID] = USED;
				pGraph->currentVertexCount++;
			}
			else {
				printf("오류, 노드 ID(!) [%d], in addVertexLG()\n", vertexID);
				ret = FAIL;
			}
		}
		else {
			printf("오류, 노드 ID(2) [%d], in addVertexLG()\n", vertexID, pGraph->maxVertexCount);
			ret = FAIL;
		}
	}
	return ret;
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID) {
	return addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, USED);
}

int addLLElementForVertex(LinkedList* pList, int position, GraphVertex vertex) {
	ListNode node = { 0, };
	node.data = vertex;
	return addLLElement(pList, position, node);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight) {
	int ret = SUCCESS;
	GraphVertex toNode = { 0, };

	if (pGraph != NULL) {
		if (checkVertexValid(pGraph, fromVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		if (checkVertexValid(pGraph, toVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}

		toNode.vertexID = toVertexID;
		toNode.weight = weight;
		addLLElementForVertex(pGraph->ppAdjEdge[fromVertexID], 0, toNode);
		pGraph->currentEdgeCount++;

		if (pGraph->graphType == GRAPH_UNDIRECTED) {
			GraphVertex fromNode;
			fromNode.vertexID = fromVertexID;
			fromNode.weight = weight;
			addLLElementForVertex(pGraph->ppAdjEdge[toVertexID], 0, fromNode);

			pGraph->currentEdgeCount++;
		}
	}
	return ret;
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID) {
	int ret = SUCCESS;

	if (vertexID >= pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED) {
		printf("오류, 노드 ID[%d]\n", vertexID);
		ret = FAIL;
	}
	return ret;
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID) {
	int ret = SUCCESS;
	int i = 0;

	if (pGraph != NULL) {
		if (checkVertexValid(pGraph, vertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		for (i = 0; i < pGraph->maxVertexCount; i++) {
			removeEdgeLG(pGraph, vertexID, i);
			removeEdgeLG(pGraph, i, vertexID);
		}
		pGraph->pVertex[vertexID] = NOT_USED;
	}
	return ret;
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID) {
	int ret = SUCCESS;

	if (pGraph != NULL) {
		if (checkVertexValid(pGraph, fromVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		if (checkVertexValid(pGraph, toVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);

		if (pGraph->graphType == GRAPH_UNDIRECTED) {
			deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
		}
	}
	return ret;
}

void deleteGraphNode(LinkedList* pList, int delVertexID) {
	int i = 0, position = 0;
	ListNode* pNode = NULL;

	position = findGraphNodePosition(pList, delVertexID);
	if (position >= 0) removeLLElement(pList, position);
}

int findGraphNodePosition(LinkedList* pList, int vertexID) {
	int i = 0, position = 0;
	ListNode* pNode = NULL;

	if (pList != NULL) {
		pNode = pList->headerNode.pLink;
		while (pNode != NULL) {
			if (pNode->data.vertexID == vertexID) return position;
			pNode = pNode->pLink;
			position++;
		}
		return -1;
	}
}