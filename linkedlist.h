#ifndef _LINKEDLIST_
#define _LINKEDLIST_
typedef struct ListNodetype {
	int data;
	struct ListNodetype *pLink;
}ListNode;
typedef struct LinkeListType {
	int currentElementCount;
	ListNode headerNode;
}LinkedList;
LinkedList *createLinkedList();
int addLLElement(LinkedList *pList, int position, ListNode element);
int removeLLElement(LinkedList *pList, int position);
ListNode *getLLElement(LinkedList *pList, int position);

void clearLinkedList(LinkedList *pList);
int getLinkedListLength(LinkedList *pList);
void deleteLinkedList(LinkedList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_
#define TRUE 1
#define FALSE 0
#endif