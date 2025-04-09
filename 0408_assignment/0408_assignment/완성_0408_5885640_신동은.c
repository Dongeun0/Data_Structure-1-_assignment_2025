#include <stdio.h>
#include <stdlib.h>
#define NULL_ITEM (elementType) {-1, -1, -1}

//linearList.h참고
//행렬 각 요소 표현
typedef struct ElementType {
	int row;//행
	int col;//열
	int val;//해당 위치의 값
}elementType;

//선형리스트
typedef struct ListType {
	int size;//리스트 최대 크기
	int last;//마지막 요소
	int move;// 항목 이동 횟수
	elementType* array;//요소 저장하는 동적 배열
}listType;

//linearList.c 참고
//지정된 크기의 새로운 리스트 생성 함수
listType* createList(int size) {
	listType* lptr;
	lptr = (listType*)malloc(sizeof(listType));
	lptr->array = (elementType*)malloc(sizeof(elementType) * size);
	lptr->size = size;//최대 크기 설정
	lptr->last = -1;//초기상태: 빔
	lptr->move = 0;//이동 횟수 초기화
	return lptr;
}

elementType readItem(listType* list, int index) {
	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index error %d in readItem\n", index);
		return NULL_ITEM;
	}
	return list->array[index];
}

int compare_item(elementType item1, elementType item2) {
	if (item1.row != item2.row) return (item1.row - item2.row);
	else return (item1.col - item2.col);
}

int ordered_insertItem(listType* list, elementType item) {
	int i, j;
	for (i = 0; i <= list->last; i++) {
		if (compare_item(list->array[i], item) > 0) break;
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
		fprintf(stderr, "Index error %d in readItem\n", index);
		return -1;
	}

	if (index > list->size) {
		fprintf(stderr, "list is full(%d) in readItem\n", index);
		return -1;
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
		fprintf(stderr, "Index error %d in deleteItem\n", index);
		return NULL_ITEM;
	}

	for (int i = index; i < list->last; i++) {
		list->array[i] = list->array[i + 1];
		list->move++;
	}

	list->last--;
	return r;
}

int printList(listType* list) {
	printf("List: size = %d, last = %d\n", list->size, list->last);
	printf("Items:\n");
	for (int i = 0; i <= list->last; i++) {
		printf("\t[%d] %d, %d, %d\n", i, list->array[i].row,
			list->array[i].col, list->array[i].val);
	}
	return 1;
}

int initList(listType* list) {
	list->last = -1;
	list->move = 0;
	return 1;
}

//행렬 합 계산 함수
listType* addMatrix(listType* list1, listType* list2) {
	listType* result;
	elementType item;

	//결과를 위한 크기의 리스트 생성
	result = createList(list1->size + list2->size);

	//행렬의 모든 요소 결과에 복사(행렬1)
	for (int i = 0; i <= list1->last; i++) {
		item = readItem(list1, i);
		ordered_insertItem(result, item);
	}
	//행렬2 각 요소 처리
	for (int i = 0; i <= list2->last; i++) {
		item = readItem(list2, i);
		
		//행과 열의 요소 찾기
		int found = 0;
		for (int j = 0; j <= result->last; j++) {
			elementType existing = readItem(result, j);
			if (existing.row == item.row && existing.col == item.col) {
				//같은 위치면 더함
				existing.val += item.val;

				deleteItem(result, j);
				ordered_insertItem(result, existing);

				found = 1;
				break;
			}
		}
		if (!found) {
			ordered_insertItem(result, item);
		}
	}
	return result;
}

int main() {
	listType* matrix1, *matrix2, *sum;
	int row, col, val;

	//첫번째 행렬 입력
	matrix1 = createList(20);
	printf("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)\n");

	while (1) {
		scanf_s("%d", &row);
		if (row == -1) break;
		scanf_s("%d %d", &col, &val);
		ordered_insertItem(matrix1, (elementType) { row, col, val });
	}

	//두번째 행렬 입력
	matrix2 = createList(20);
	printf("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)\n");
	while (1) {
		scanf_s("%d", &row);
		if (row == -1) break;
		scanf_s("%d %d", &col, &val);
		ordered_insertItem(matrix2, (elementType) { row, col, val });
	}

	//두 행렬의 합 계산
	sum = addMatrix(matrix1, matrix2);

	printf("두 행렬의 합\n");
	printList(sum);

	//메모리 해제
	free(matrix1->array);
	free(matrix1);
	free(matrix2->array);
	free(matrix2);
	free(sum->array);
	free(sum);

	return 0;
}