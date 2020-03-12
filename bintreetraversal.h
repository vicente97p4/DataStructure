#include"bintreesearch(it).h"
#include"bintreelinkedqueue.h"
#include"bintreelinkedstack.h"
#ifndef _BIN_TREE_TRAVERSAL_
#define _BIN_TREE_TRAVERSAL_

void preorderTraversalBinTree(BinTree *pBinTree);
void inorderTraversalBinTree(BinTree *pBinTree);
void postorderTraversalBinTree(BinTree *pBinTree);
void levelorderTraversalBinTree(BinTree *pBinTree);
int pushLSBinTreeNode(LinkedStack* pStack, BinTreeNode *pNode);
int enqueueLQBinTreeNode(LinkedQueue* pQueue, BinTreeNode* pNode);
#endif