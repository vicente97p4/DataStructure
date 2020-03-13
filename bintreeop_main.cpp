#include<stdio.h>
#include<stdlib.h>
#include"bintreeop.h"

BinTree* createExampleBinTree();
int main() {
	int compareResult = FALSE;
	int count = 0;
	BinTree *pBinTree = NULL, *pCopyBinTree = NULL;

	pBinTree = createExampleBinTree();
	printf("이진 트리 원본:\n");
	displayBinTree(pBinTree);

	pCopyBinTree = copyBinTree(pBinTree);
	printf("이진 트리 복사본:\n");
	displayBinTree(pCopyBinTree);

	compareResult = equalBinTree(pBinTree, pCopyBinTree);
	printf("\n이진 트리 비교 결과: (%d)\n", compareResult);

	count = getNodeCountBT(pBinTree);
	printf("\n이진 트리 노드 개수: %d\n", count);

	count = getLeafNodeCountBT(pBinTree);
	printf("\n이진 트리 단말 노드 개수: %d\n", count);

	count = getHeightBT(pBinTree);
	printf("\n이진 트리의 높이: %d\n", count);

	deleteBinTree(pBinTree);
	deleteBinTree(pCopyBinTree);
	return 0;
}

BinTree* createExampleBinTree() {
	BinTree *pReturn = NULL;
	/* 중략 */
	return pReturn;
}