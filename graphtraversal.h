#include"linkedgraph.h"
#include"linkedstack.h"
#include"linkedqueue.h"
#ifndef _GRAPH_TRAVERSAL_
#define _GRAPH_TRAVERSAL_

void traversalDFS(LinkedGraph* pGraph, int startVertexID);
void traversalBFS(LinkedGraph* pGraph, int startVertexID);
int pushLSForDFS(LinkedStack* pStack, int nodeID);
int enqueueLQForBFS(LinkedQueue* pQueue, int nodeID);
#endif