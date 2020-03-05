#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"
#include"polylist.h"

int main() {
	LinkedList *pListA = NULL;
	LinkedList *pListB = NULL;
	LinkedList *pListC = NULL;

	pListA = createLinkedList();
	pListB = createLinkedList();
	if (pListA != NULL && pListB != NULL) {
		addPolyNodeLast(pListA, 6, 6);
		addPolyNodeLast(pListA, 4, 5);
		addPolyNodeLast(pListA, 2, 2);
		displayPolyList(pListA);

		addPolyNodeLast(pListB, 1, 5);
		addPolyNodeLast(pListB, 2, 4);
		addPolyNodeLast(pListB, 3, 2);
		addPolyNodeLast(pListB, 4, 0);
		displayPolyList(pListB);

		pListC = polyAdd(pListA, pListB);
		if (pListC != NULL) {
			displayPolyList(pListC);
			deleteLinkedList(pListC);
		}
		deleteLinkedList(pListA);
		deleteLinkedList(pListB);
	}
	return 0;
}