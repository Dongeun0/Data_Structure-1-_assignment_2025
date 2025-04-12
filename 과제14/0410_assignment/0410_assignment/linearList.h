#pragma once

typedef struct ElementType {
	int coef, expo;//계수, 지수
} elementType;

#define Null_Item (elementType) {0, 0}

typedef struct ListType {
	int size;//리스트 최대 크기
	int last;//마지막 요소
	int move;// 항목 이동 횟수
	elementType* array;//요소 저장하는 동적 배열
} listType;

extern listType* createList(int size);
extern int destroyList(listType* list);
extern elementType readItem(listType* list, int index);
extern elementType deleteItem(listType* list, int index);
extern int insertItem(listType* list, int index, elementType item);
extern int printList(listType* list);
extern int initList(listType* list);
extern int ordered_insertItem(listType* list, elementType item);