#include<stdio.h>
#include<stdlib.h>
#include"arraygraph.h"
void displayArrayGraph(ArrayGraph* pGraph) {
	int i = 0, j = 0;

	for (i = 0; i < pGraph->maxVertexCount; i++) {
		for (j = 0; j < pGraph->maxVertexCount; j++) {
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int i = 0;
	ArrayGraph *pG1 = NULL;
	ArrayGraph *pG2 = NULL;
	ArrayGraph *pG4 = NULL;
	
	pG1 = createArrayGraph(6);
	pG2 = createArrayDirectedGraph(6);
	pG4 = createArrayDirectedGraph(6);
	if (pG1 != NULL && pG2 != NULL && pG4 != NULL) {
		for (i = 0; i < 6; i++) {
			addVertexAG(pG1, i);
			addVertexAG(pG2, i);
			addVertexAG(pG4, i);
		}
		
		addEdgeAG(pG1, 0, 1);
		addEdgeAG(pG1, 0, 2);
		addEdgeAG(pG1, 1, 2);
		addEdgeAG(pG1, 2, 3);
		addEdgeAG(pG1, 3, 4);
		addEdgeAG(pG1, 3, 5);
		addEdgeAG(pG1, 4, 5);
		addEdgeAG(pG2, 0, 1);
		addEdgeAG(pG2, 1, 2);
		addEdgeAG(pG2, 2, 0);
		addEdgeAG(pG2, 2, 1);
		addEdgeAG(pG2, 2, 3);
		addEdgeAG(pG2, 3, 2);
		addEdgeAG(pG2, 3, 4);
		addEdgeAG(pG2, 4, 5);
		addEdgeAG(pG2, 5, 3);
		
		addEdgewithWeightAG(pG4, 0, 1, 4);
		addEdgewithWeightAG(pG4, 1, 2, 1);
		addEdgewithWeightAG(pG4, 2, 0, 2);
		addEdgewithWeightAG(pG4, 2, 1, 3);
		addEdgewithWeightAG(pG4, 2, 3, 2);
		addEdgewithWeightAG(pG4, 3, 2, 1);
		addEdgewithWeightAG(pG4, 3, 4, 1);
		addEdgewithWeightAG(pG4, 4, 5, 1);
		addEdgewithWeightAG(pG4, 5, 3, 2);

		printf("G!: Undirected\n");
		displayArrayGraph(pG1);
		printf("\nG2: Directed\n");
		displayArrayGraph(pG2);
		printf("\nG!: Directed Weighted\n");
		displayArrayGraph(pG4);

		/*
		deleteArrayGraph(pG1);
		deleteArrayGraph(pG2);
		deleteArrayGraph(pG4);
		*/
	}
	return 0;
}