#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

void displayLinkedList(LinkedList *pList) {
	int i = 0;
	if (pList != NULL) {
		printf("���� ���� ����: %d\n", pList->currentElementCount);
		for (i = 0; i < pList->currentElementCount; i++) {
			printf("[%d], %d\n", i, getLLElement(pList, i)->data);
		}
	}
	else {
		printf("���Ұ� �����ϴ�.\n");
	}
}
int main() {
	int i = 0;
	int arrayCount = 0;
	LinkedList *pList = NULL;
	ListNode *pNode = NULL;
	ListNode node;

	pList = createLinkedList();
	if (pList != NULL) {
		node.data = 1;
		addLLElement(pList, 0, node);
		node.data = 3;
		addLLElement(pList, 1, node);
		node.data = 5;
		addLLElement(pList, 2, node);
		displayLinkedList(pList);
		removeLLElement(pList, 0);
		displayLinkedList(pList);
		deleteLinkedList(pList);
	}
	return 0;
}