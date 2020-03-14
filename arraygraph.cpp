#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount) {
	int i = 0, j = 0;
	ArrayGraph *pReturn = NULL;

	if (maxVertexCount > 0) {
		pReturn = (ArrayGraph*)malloc(sizeof(ArrayGraph));
		if (pReturn == NULL) {
			printf("����, �޸� �Ҵ�(1), in createArrayGraph()\n");
			return NULL;
		}
		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
	}
	else {
		printf("����, �ִ� ��� ������ 0���� Ŀ���մϴ�.\n");
		return NULL;
	}
	pReturn->pVertex = (int*)malloc(sizeof(int)*maxVertexCount);
	if (pReturn->pVertex == NULL) {
		printf("����, �޸��Ҵ�(2), in createArrayGraph()\n");
		if (pReturn != NULL) free(pReturn);
		return NULL;
	}
	pReturn->ppAdjEdge = (int**)malloc(sizeof(int*)*maxVertexCount);
	if (pReturn->ppAdjEdge == NULL) {
		printf("����, �޸��Ҵ�(3), in createArrayGraph()\n");
		if (pReturn->pVertex != NULL)free(pReturn->pVertex);
		if (pReturn != NULL)free(pReturn);
		return NULL;
	}

	for (i = 0; i < maxVertexCount; i++) {
		pReturn->ppAdjEdge[i] = (int*)malloc(sizeof(int)*maxVertexCount);
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("����, �޸��Ҵ�(4), in createArrayGraph()\n");
			for (j = 0; j < i; j++) {
				if (pReturn->ppAdjEdge[j] != NULL)free(pReturn->ppAdjEdge[j]);
			}
			if (pReturn->ppAdjEdge != NULL)free(pReturn->ppAdjEdge);
			if (pReturn->pVertex != NULL) free(pReturn->pVertex);
			if (pReturn != NULL) free(pReturn);
			return NULL;
		}
	}

	memset(pReturn->pVertex, NOT_USED, sizeof(int)*maxVertexCount);
	for (i = 0; i < maxVertexCount; i++)
		memset(pReturn->ppAdjEdge[i], 0, sizeof(int)*maxVertexCount);
	return pReturn;
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount) {
	ArrayGraph* pReturn = NULL;
	pReturn = createArrayGraph(maxVertexCount);
	if (pReturn != NULL) pReturn->graphType = GRAPH_DIRECTED;
	return pReturn;
}

int addVertexAG(ArrayGraph* pGraph, int vertexID) {
	int ret = SUCCESS;

	if (pGraph != NULL) {
		if (vertexID < pGraph->maxVertexCount) {
			if (pGraph->pVertex[vertexID] == NOT_USED) {
				pGraph->pVertex[vertexID] = USED;
				pGraph->currentVertexCount++;
			}
			else {
				printf("����, �̹� �����ϴ� ���[%d], in addVertexAG()\n", vertexID);
				ret = FAIL;
			}
		}
		else {
			printf("����, �ִ� ��� ���� �ʰ� [%d], in addVertexAG()\n", pGraph->maxVertexCount);
			ret = FAIL;
		}
	}
	return ret;
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight) {
	int ret = SUCCESS;

	if(pGraph !=NULL){
		if (checkVertexValid(pGraph, fromVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		if (checkVertexValid(pGraph, toVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;

		if (pGraph->graphType == GRAPH_UNDIRECTED) {
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
		}
	}
	return ret;
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID) {
	int ret = SUCCESS;

	if (vertexID >= pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED) {
		printf("����, ��� ����[%d]\n", vertexID);
		ret = FAIL;
	}
	return ret;
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID) {
	return addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, USED);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID) {
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
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;

		if (pGraph->graphType == GRAPH_UNDIRECTED) pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	}
	return ret;
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID) {
	int ret = SUCCESS;
	int i = 0;

	if (pGraph != NULL) {
		if (checkVertexValid(pGraph, vertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		for (i = 0; i < pGraph->maxVertexCount; i++) {
			removeEdgeAG(pGraph, vertexID, i);
			removeEdgeAG(pGraph, i, vertexID);
		}
		pGraph->pVertex[vertexID] = NOT_USED;
	}
	return ret;
}