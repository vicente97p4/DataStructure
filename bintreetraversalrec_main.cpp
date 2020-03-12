#include<stdio.h>
#include<stdlib.h>
#include"bintreetraversalrec.h"

BinTree* createExampleBinTree();

int main() {
	BinTree* pBinTree = NULL;
	pBinTree = createExampleBinTree();
	if (pBinTree != NULL) {
		printf("Preorder Recursive Traversal\n");
		preorderTraversalRecursiveBinTree(pBinTree);

		printf("\nInorder Recursive Traversal\n");
		inorderTraversalRecursiveBinTree(pBinTree);

		printf("\nPostorder Recursive Traversal\n");
		postorderTraversalRecursiveBinTree(pBinTree);

		deleteBinTree(pBinTree);
	}
	return 0;
}

BinTree* createExampleBinTree() {
	BinTree *pReturn = NULL;
	/* Áß·« */
	return pReturn;
}