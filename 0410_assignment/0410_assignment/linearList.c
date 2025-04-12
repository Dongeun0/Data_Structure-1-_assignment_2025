#include <stdio.h>
#include <stdlib.h>

#include "linearList.h"

//지정된 크기의 새로운 리스트 생성 함수
listType* createList(int size) {
    listType* lptr;
    lptr = (listType*)malloc(sizeof(listType));
    lptr->array = (elementType*)malloc(sizeof(elementType) * size);
    lptr->size = size; // 최대 크기 설정
    lptr->last = -1; // 초기상태: 빔
    lptr->move = 0; // 이동 횟수 초기화
    return lptr;
}

int destroyList(listType* list) {
    free(list->array);
    free(list);
    return 1;
}

elementType readItem(listType* list, int index) {
    if (index < 0 || index > list->last) {
        printf(stderr, "Index error %d in readItem\n", index);
        return Null_Item;
    }
    return list->array[index];
}

int compare_item(elementType item1, elementType item2) {
    return (item2.expo - item1.expo);
}

int ordered_insertItem(listType* list, elementType item) {
    int i, j;

    // 리스트 크기 확인 및 필요시 확장
    if (list->last >= list->size - 1) {
        list->size *= 2;
        list->array = (elementType*)realloc(list->array, sizeof(elementType) * list->size);
    }

    for (i = 0; i <= list->last; i++) {
        if (list->array[i].expo == item.expo) {
            list->array[i].coef += item.coef;
            return 1;
        }
        if (list->array[i].expo < item.expo) break;
    }

    for (j = list->last + 1; j > i; j--) {
        list->array[j] = list->array[j - 1];
        list->move++;
    }

    list->array[i] = item;
    list->last++;
    return 1;
}

int insertItem(listType* list, int index, elementType item) {
    if (index < 0 || index >(list->last + 1)) {
        printf(stderr, "Index error %d in insertItem\n", index);
        return -1;
    }

    if (list->last >= list->size - 1) {
        list->size *= 2;
        list->array = (elementType*)realloc(list->array, sizeof(elementType) * list->size);
    }

    for (int i = list->last + 1; i > index; i--) {
        list->array[i] = list->array[i - 1];
        list->move++;
    }

    list->array[index] = item;
    list->last++;
    return 1;
}

elementType deleteItem(listType* list, int index) {
    elementType r = list->array[index];
    if (index < 0 || index > list->last) {
        printf(stderr, "Index error %d in deleteItem\n", index);
        return Null_Item;
    }

    for (int i = index; i < list->last; i++) {
        list->array[i] = list->array[i + 1];
        list->move++;
    }

    list->last--;
    return r;
}

int printList(listType* list) {
    printf("List: size = %d, last = %d, move = %d\n", list->size, list->last, list->move);
    printf("Items: P(x) = ");

    for (int i = 0; i <= list->last; i++) {
        if (i > 0 && list->array[i].coef > 0) {
            printf("+");
        }

        if (list->array[i].expo == 0) {
            printf("%d", list->array[i].coef);
        }
        else if (list->array[i].expo == 1) {
            printf("%dx", list->array[i].coef);
        }
        else {
            printf("%dx^%d", list->array[i].coef, list->array[i].expo);
        }
    }
    printf("\n");
    return 1;
}

int initList(listType* list) {
    list->last = -1;
    list->move = 0;
    return 1;
}