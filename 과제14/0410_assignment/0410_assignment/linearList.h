#pragma once

typedef struct ElementType {
	int coef, expo;//���, ����
} elementType;

#define Null_Item (elementType) {0, 0}

typedef struct ListType {
	int size;//����Ʈ �ִ� ũ��
	int last;//������ ���
	int move;// �׸� �̵� Ƚ��
	elementType* array;//��� �����ϴ� ���� �迭
} listType;

extern listType* createList(int size);
extern int destroyList(listType* list);
extern elementType readItem(listType* list, int index);
extern elementType deleteItem(listType* list, int index);
extern int insertItem(listType* list, int index, elementType item);
extern int printList(listType* list);
extern int initList(listType* list);
extern int ordered_insertItem(listType* list, elementType item);