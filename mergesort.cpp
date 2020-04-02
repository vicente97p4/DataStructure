#include<stdio.h>
#include<stdlib.h>

void printArray(int value[], int count);
void mergeSortInternal(int value[], int buffer[], int start, int middle, int end) {
	int i = 0, j = 0, k = 0, t = 0;
	i = start;
	j = middle + 1;
	k = start;
	while (i <= middle && j <= end) {
		if (value[i] <= value[j]) {
			buffer[k] = value[i];
			i++;
		}
		else {
			buffer[k] = value[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (t = j; t <= end; t++, k++) {
			buffer[k] = value[t];
		}
	}
	else {
		for (t = i; t <= middle; t++, k++) {
			buffer[k] = value[t];
		}
	}

	for (t = start; t <= end; t++) {
		value[t] = buffer[t];
	}
	printf("start-%d, middle-%d, end-%d, ", start, middle, end);
	for (t = start; t <= end; t++) {
		printf("%d ", value[t]);
	}
	printf("\n");
}
void mergeSort(int value[], int buffer[], int start, int end) {
	int middle = 0;
	if (start < end) {
		middle = (start + end) / 2;
		mergeSort(value, buffer, start, middle);
		mergeSort(value, buffer, middle + 1, end);
		mergeSortInternal(value, buffer, start, middle, end);
	}
}

int main(int argc, char *argv[]) {
	int value[] = { 80,50,70,10,60,20,40,30 };
	int buffer[8];
	printf("Before Sort\n");
	printArray(value, 8);

	mergeSort(value, buffer, 0, 7);

	return 0;
}
void printArray(int value[], int count) {
	for (int i = 0; i < count; i++) {
		printf("%d ", value[i]);
	}
	printf("\n");
}