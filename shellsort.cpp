#include<stdio.h>
#include<stdlib.h>

void printArray(int value[], int count);
void shellInsertionSort(int value[], int start, int end, int interval);

void shellSort(int value[], int count) {
	int i = 0, interval = 0;

	interval = count / 2;
	while (interval >= 1) {
		for (i = 0; i < interval; i++)
			shellInsertionSort(value, i, count - 1, interval);

		printf("Interval-%d, ", interval);
		printArray(value, count);

		interval = interval / 2;
	}
}
void shellInsertionSort(int value[], int start, int end, int interval) {
	int i = 0;
	int item = 0, index = 0;
	for (i = start + interval; i <= end; i = i + interval) {
		item = value[i];
		index = i - interval;
		while ((index >= start) && item < value[index]) {
			value[index + interval] = value[index];
			index = index - interval;
		}
		value[index + interval] = item;
	}
}
int main(int argc, char *argv[]) {
	int value[] = { 80,50,70,10,60,20,40,30 };

	printf("Before Sort\n");
	printArray(value, 8);

	shellSort(value, 8);

	printf("\nAfter Sort\n");
	printArray(value, 8);

	return 0;
}
void printArray(int value[], int count) {
	for (int i = 0; i < count; i++) {
		printf("%d ", value[i]);
	}
	printf("\n");
}