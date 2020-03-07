#include<stdio.h>
#include<stdlib.h>
#include"maputil.h"

int main() {
	LinkedStack *pStack = NULL;
	MapPosition startPos, endPos;

	int mazeArray[HEIGHT][WIDTH] = {
		{ 0,0,1,1,1,1,1,1},
		{ 1,0,0,0,0,0,0,1},
		{ 1,1,1,0,1,1,1,1},
		{ 1,1,1,0,1,1,1,1},
		{ 1,0,0,0,0,0,0,1},
		{ 1,0,1,1,1,1,1,1},
		{ 1,0,0,0,0,0,0,0},
		{ 1,1,1,1,1,1,1,0},
	};
	pStack = createLinkedStack();
	if (pStack != NULL) {
		startPos.x = 0;
		startPos.y = 0;
		endPos.x = 7;
		endPos.y = 7;
		
		printMaze(mazeArray);
		findPath(mazeArray, startPos, endPos, pStack);
		showPath(pStack, mazeArray);
		
		deleteLinkedStack(pStack);
	}
	return 0;
}