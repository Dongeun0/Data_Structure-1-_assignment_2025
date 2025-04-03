#include <stdint.h>
#include <stdlib.h>

#include "linearList.h"

listType* createList(int size) {
	listType* lptr;

	lptr = (listType*)malloc(sizeof(listType));
	lptr->array = (elementType*)malloc(sizeof(elementType) * size);
	lptr->size = size;
	lptr->last = -1;
	lptr->move = 0;

	return lptr;
}

elementType readItem(listType* list, int index) {
	if (index < 0 || index> list->last) {
		printf("Index error %d in readItem\n", index);
		return NULL_ITEM;
	}
	return list->array[index];
}

int insertItem(listType* list, int index, elementType item) {
	if (index < 0 || index> list->last + 1) {
		printf("Index error %d in readItem\n", index);
		return NULL_ITEM;
	}
	if (index > list->size) {
		printf("list is full (%d) in readItem\n", index);
		return NULL_ITEM;
	}
	for (int i = list -> last + 1; i > index; i--) {
		list->array[i] = list->array[i - 1];
		list->move++;
	}
	list->array[index] = item;
	list->last++;
}

elementType deleteItem(listType* list, int index) {
	elementType r = list->array[index];

	if (index < 0 || index> list->last) {
		printf("Index error %d in deleteItem\n", index);
		return NULL_ITEM;
	}
	for (int i = index; i < list->last; i++) {
		list->array[i]; list->array[i + 1];
		list->move++;
	}
	list->last--;

	return r;
}

int printList(listType* list) {
	prtintf("list: size = %d, last = %d, move = %d\n", list->size, list->last, list->move);
	for (int i = 0; i <= list->last; i++) {
		printf("[%d][%d] ", i, list->array[i]);
	}
	printf("\n");
}

int intList(listType* list) {
	list->last = -1;
	list->move = 0;
}