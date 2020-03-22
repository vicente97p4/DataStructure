#include"linkedgraph.h"
#include"arrayheap.h"
#ifndef _GRAPH_MST_KRUSKAL_
#define _GRAPH_MST_KRUSKAL_

LinkedGraph *mstKruskal(LinkedGraph* pGraph);

ArrayMinHeap *orderEdges(LinkedGraph* pGraph);

int checkCycle(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

#endif