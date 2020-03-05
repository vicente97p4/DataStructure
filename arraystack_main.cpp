#include<stdio.h>
#include<stdlib.h>
#include"arraystack.h"

void displayArrayStack(ArrayStack *pStack) {
	int i = 0;
	if (pStack != NULL) {
		int size = pStack->maxElementCount;
		int top = pStack->currentElementCount;

		printf("���� ũ��: %d, ���� ��� ����: %d\n", pStack->maxElementCount, pStack->currentElementCount);
		for (i = size - 1; i >= top; i--)
			printf("[%d]-[Empty]\n", i);
		for (i = top - 1; i >= 0; i--)
			printf("[%d]-[%c]\n", i, pStack->pElement[i].data);
	}
}

int main() {
	ArrayStack *pStack = NULL;
	ArrayStackNode *pNode = NULL;
	char value = 0;

	pStack = createArrayStack(6);
	if (pStack != NULL) {
		ArrayStackNode node1 = { 'A' };
		ArrayStackNode node2 = { 'B' };
		ArrayStackNode node3 = { 'C' };
		ArrayStackNode node4 = { 'D' };

		pushAS(pStack, node1);
		pushAS(pStack, node2);
		pushAS(pStack, node3);
		pushAS(pStack, node4);
		displayArrayStack(pStack);

		pNode = popAS(pStack);
		if (pNode != NULL) {
			printf("Pop ��-[%c]\n", pNode->data);
			free(pNode);
		}
		else
			printf("����(Empty) ����\n");
		displayArrayStack(pStack);

		pNode = peekAS(pStack);
		if (pNode != NULL)
			printf("Peek ��-[%c]\n", pNode->data);
		else
			printf("����(Empty) ����\n");
		displayArrayStack(pStack);
	}
	return 0;
}