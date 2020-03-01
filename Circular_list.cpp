#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;
ListNode* create_node(element data, ListNode *link) {
	ListNode *new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	
	new_node->data = data;
	new_node->link = link;
	return new_node;
}
void display(ListNode *head) {
	ListNode *p;
	if (head == NULL) return;

	p = head;
	do {
		p = p->link;
		printf("%d->", p->data);
	} while (p != head);
	printf("\n");
}
void insert_first(ListNode **phead, ListNode *node) {
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}
void insert_last(ListNode **phead, ListNode *node) {
	if (*phead == NULL) {
		*phead == node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}

int main() {
	ListNode *list1 = NULL;

	insert_first(&list1, create_node(10, NULL));
	insert_first(&list1, create_node(20, NULL));
	insert_last(&list1, create_node(30, NULL));
	display(list1);
}