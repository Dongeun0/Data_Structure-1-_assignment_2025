#pragma once
#define NULL_ITEM (elementType)-1

// 배열에 들어가는 항목을 관리
//typedef struct {
//	char name[20];
//	char telphone[3][3][3];
//	char address[40];
//	int age;
//}elementType;

typedef int elementType;
//여러개를 저장할 공간을 만들어주기
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
