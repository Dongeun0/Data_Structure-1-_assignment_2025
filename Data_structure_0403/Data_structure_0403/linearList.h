#pragma once

#define NULL_ITEM (elementType) {-1, -1, -1}

// �迭�� ���� �׸��� ����
//typedef struct {
//	char name[20];
//	char telphone[3][3][3];
//	char address[40];
//	int age;
//}elementType;

typedef struct ElementType {
	int row;
	int col;
	int val;
}elementType;

//�������� ������ ������ ������ֱ�
typedef struct ListType {
	int size;
	int last;
	int move;
	elementType* array;
} listType;

#define Null_Item (elementType) {0, 0}
typedef struct ElementType {
	int coef, expo;
}elementType;

extern listType* createList(int size);
extern elementType readItem(listType* list, int index);
extern elementType deleteItem(listType* list, int index);
extern int insertItem(listType* list, int index, elementType item);
extern int printList(listType* list);
extern int initList(listType* list);
extern int ordered_insertItem(listType* list, elementType);
extern int destroyList(listType* list);