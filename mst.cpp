//2017030073_¿Ã∞≠πŒ_11802
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int e, v, counter=0;
typedef struct weight {
	int x;
	int y;
	int w;
}weight;
typedef struct node {
	struct node* p;
	int rank;
}node;

weight wei[499501];
weight answer[499501];
node* arr[1001];

node* find_set(node* n) {
	if (n->p != n)
		n->p = find_set(n->p);
	return n->p;
}
bool compare(weight a, weight b) {
	if (a.w != b.w) return a.w < b.w;
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
void link(node* x, node* y) {
	if (x->rank > y->rank)
		y->p = x;
	else {
		x->p = y;
		if (x->rank == y->rank)
			y->rank++;
	}
}
void UNION(node* x, node* y) {
	link(find_set(x), find_set(y));
}
int main() {
	int i;
	scanf("%d %d", &v, &e);
	for (i = 1; i <= v; i++) {
		arr[i] = (node*)malloc(sizeof(node));
		arr[i]->p = arr[i];
		arr[i]->rank = 0;
	}
	for (i = 1; i <= e; i++) {
		scanf("%d %d %d", &(wei[i].x),&(wei[i].y),&(wei[i].w));
	}

	sort(wei+1, wei+e+1, compare);
	
	for (i = 1; i <= e; i++) {
		if (find_set(arr[wei[i].x]) != find_set(arr[wei[i].y])) {
			answer[counter++] = wei[i];
			UNION(arr[wei[i].x], arr[wei[i].y]);
		}
	}
	printf("%d\n", counter);
	for (i = 0; i < counter; i++)
		printf("%d %d %d\n", answer[i].x, answer[i].y, answer[i].w);
	return 0;
}