#include<stdio.h>
#include<stdlib.h>
#include"graphmst.h"
#include"graphlinkedlist.h"
#include"linkedgraph.h"

LinkedGraph* mstKruskal(LinkedGraph* pGraph) {
	LinkedGraph* pReturn = NULL;
	int i = 0;
	int maxNodeCount = 0;
	int currentNodeCounde = 0;
	int edgeCount = 0;
	int isCycle = 0;
	ArrayMinHeap *pMinHeap = NULL;
	HeapNode *pHeapNode = NULL;

	if (pGraph == NULL) {
		printf("Graph is NULL\n");
		return NULL;
	}

	maxNodeCount = getMaxVertexCountLG(pGraph);
	currentNodeCounde = getVertexCountLG(pGraph);
	edgeCount = getEdgeCountLG(pGraph);
}