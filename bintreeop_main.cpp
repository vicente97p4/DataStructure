#include<stdio.h>
#include<stdlib.h>
#include"bintreeop.h"

BinTree* createExampleBinTree();
int main() {
	int compareResult = FALSE;
	int count = 0;
	BinTree *pBinTree = NULL, *pCopyBinTree = NULL;

	pBinTree = createExampleBinTree();
	printf("���� Ʈ�� ����:\n");
	displayBinTree(pBinTree);

	pCopyBinTree = copyBinTree(pBinTree);
	printf("���� Ʈ�� ���纻:\n");
	displayBinTree(pCopyBinTree);

	compareResult = equalBinTree(pBinTree, pCopyBinTree);
	printf("\n���� Ʈ�� �� ���: (%d)\n", compareResult);

	count = getNodeCountBT(pBinTree);
	printf("\n���� Ʈ�� ��� ����: %d\n", count);

	count = getLeafNodeCountBT(pBinTree);
	printf("\n���� Ʈ�� �ܸ� ��� ����: %d\n", count);

	count = getHeightBT(pBinTree);
	printf("\n���� Ʈ���� ����: %d\n", count);

	deleteBinTree(pBinTree);
	deleteBinTree(pCopyBinTree);
	return 0;
}

BinTree* createExampleBinTree() {
	BinTree *pReturn = NULL;
	/* �߷� */
	return pReturn;
}