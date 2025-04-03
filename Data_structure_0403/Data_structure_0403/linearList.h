#pragma once
#define NULL_ITEM (elementType)-1

// �迭�� ���� �׸��� ����
//typedef struct {
//	char name[20];
//	char telphone[3][3][3];
//	char address[40];
//	int age;
//}elementType;

typedef int elementType;
//�������� ������ ������ ������ֱ�
typedef struct ListType {
	int size;
	int last;
	int move;
	elementType *array;
}listType;

extern listType* createList(int size);
extern elementType readItem(listType* list, int index);
extern elementType deleteItem(listType* list, int index);
extern int printList(listType* list);
extern int intList(listType* list);
