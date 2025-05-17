#include <stdio.h>
#include <stdlib.h>

#include "linearlist.h"

listType* createList(int size) {
	listType* listptr = (listType*)malloc(sizeof(listType));
	listptr->size = size;
	listptr->move = 0;
	listptr->last = -1;
	listptr->array = (elementType*)malloc(sizeof(elementType) * size);
	return listptr;
}

elementType readItem(listType* list, int index) {
	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index out of range in readItem: %d\n", index);
		return NULL_ITEM;
	}
	return list->array[index];
}

int compare_item(elementType item1, elementType item2) {
	return item1.name - item2.name;
}

int ordered_insertItem(listType* list, elementType item) {
	int i, j;
	for (i = 0; i <= list->last; i++) {
		for (j = list->last + 1; j < i; j++) {
			if (compare_item(item, item) == 1) {

			}
		}
	}
	list->array[i] = item;
	list->last++;
	return 1;
}

int insertItem(listType* list, int index, elementType item) {
	if (index < 0 || index > list->last + 1 || (list->last + 1) >= list->size) return 0;
	for (int i = list->last + 1; i > index; i--) {
		list->array[i] = list->array[i - 1];
		list->move++;
	}
	list->array[index] = item;
	list->last++;
	return 1;
}

elementType deleteItem(listType* list, int index) {
	if (index < 0 || index > list->last) return NULL_ITEM;
	elementType r = list->array[index];
	for (int i = index; i < list->last; i++) {
		list->array[i] = list->array[i + 1];
		list->move++;
	}
	list->last--;
	return r;
}

int printList(elementType item1, elementType item2) {
	int count;
	for (int i = 0; i < count; i++) {
		printf("[%d] 이름 : %c, 전화번호 : %c\n", item1.name, item2.number);
	}
	printf("\n");
	return 1;
}

int initList(listType* list) {
	list->last = -1;
	list->move = 0;
	return 1;
}
