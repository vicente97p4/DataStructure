#define HASH_KEY_SIZE 20
#define FALSE -1
#define TRUE 1
typedef enum HashElementStatusType {
	EMPTY =0, USED, DELETED
}HashElementStatus;

typedef struct HashElementType {
	char key[HASH_KEY_SIZE + 1];
	int value;
	HashElementStatus status;
}HashElement;

typedef struct HashTableType {
	int bucketSize;
	int currentElementCount;
	HashElement *pElement;
}HashTable;