#include<stdio.h>
#define FAIL -1
int binarySearchRecursive(int value[], int start, int end, int key) {
	int ret = FAIL;
	int middle = 0;

	if (start <= end) {
		middle = (start + end) / 2;
		if (key == value[middle]) ret = middle;
		else if (key < value[middle]) ret = binarySearchRecursive(value, start, middle - 1, key);
		else ret = binarySearchRecursive(value, middle + 1, end, key);
	}
	return ret;
}

int binarySearch(int value[], int start, int end, int key) {
	int ret = FAIL;
	int tempStart = 0, tempEnd = 0;
	int middle = 0;

	tempStart = start;
	tempEnd = end;
	while (tempStart <= tempEnd) {
		middle = (tempStart + tempEnd) / 2;
		if (key == value[middle]) {
			ret = middle;
			break;
		}
		else if (key < value[middle]) tempEnd = middle - 1;
		else tempStart = middle + 1;
	}
	return ret;
}