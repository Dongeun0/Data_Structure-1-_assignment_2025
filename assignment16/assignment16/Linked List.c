#include <stdio.h>
#include <stdlib.h>

#include "Linked List.h"

linkedList_h* createLinkedList(void) {
	linkedList_h* lptr;

	lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->head = (listNode*)NULL;
	lptr->follow = 0;
	return lptr;
}

void destroyLinkedList(linkedList_h* L) {
	listNode* p;

	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;  // L->head = p->link;
		free(p);
	}
	free(L);
}

int printList(linkedList_h* L) {
	listNode* lptr = L->head;

	printf("Linked List(%d): ", L->follow);
	while (lptr->link != (listNode*)NULL) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d] \n", lptr->data);
}

void insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L->head; //(1)
	L->head = newNode;  //(2)

	return 0;
}

void insertLastNode(linkedList_h* L, elementType item) {
	listNode* temp, * newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = (listNode*)NULL;

	temp = L->head;
	if (temp == (listNode*)NULL) {
		L->head = newNode;
		return;
	}

	while (temp->link != (listNode*)NULL) {
		temp = temp->link;
		L->follow++;
	}

	temp->link = newNode;

	return;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item) {

	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) {
		newNode->link = (listNode*)NULL;
		L->head = newNode;
	}
	else if (pre == (listNode*)NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertNthNode(linkedList_h* L, int loc, elementType item) {
	if (L->head == (listNode*)NULL) {
		if (loc == 0) insertFirstNode(L, item);
		else fprintf(stderr, "[insertNthNode: list empty and loc not 0\n");
		return;
	}
	else {
		if (loc == 0) insertFirstNode(L, item);
		else {
			int i = loc; listNode* pre = L->head;
			while (i > 1 && pre->link != (listNode*)NULL) {
				i--, pre = pre->link;
				L->follow++;
			}
			if (i == 1) insertMiddleNode(L, pre, item);
			else fprintf(stderr, "[insertNthNode: location error");

		}
		return;
	}
}

int compare_item(elementType first, elementType second) {
	return (first - second);
}

void ordered_insertNode(linkedList_h* L, elementType item) {
	listNode* pre;

	if (L->head == (listNode*)NULL) insertFirstNode(L, item);
	else {
		if (compare_item(L->head->data, item) > 0)
			insertFirstNode(L, item);
		else {
			pre = L->head;
			while (pre->link != (listNode*)NULL) {
				if (compare_item(pre->data, item) < 0 &&
					compare_item(pre->link->data, item) > 0) break;
				pre = pre->link;
				L->follow++;
			}
			insertMiddleNode(L, pre, item);
		}
	}
}

void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	if (L->head == (listNode*)NULL) return;
	/* if (L->head->link == (listNode*)NULL) {
		free(L->head);
		L->head = (listNode*)NULL;
		return;
	} */
	else if (p == (listNode*)NULL) return;
	else {
		pre = L->head;
		while (pre->link != p && p->link != (listNode*)NULL) {
			pre = pre->link;
			L->follow++;
		}
		if (pre->link == p) {
			pre->link = p->link; // 
			free(p);
		}
		else {
			fprintf(stderr, " delete item not in the list\n");
		}
	}
}

void printHeadTail(linkedList_h* L) {
	if (L->head == NULL) {
		printf("Head/Tail > 리스트가 비어 있습니다.\n");
		return;
	}

	// 첫 번째 노드 (헤드) 출력
	printf("Head: [%d]\n", L->head->data);

	// 마지막 노드 (테일) 출력을 위해 마지막 노드까지 이동
	listNode* temp = L->head;
	while (temp->link != NULL) {
		temp = temp->link;
	}
	printf("Tail: [%d]\n", temp->data);
}