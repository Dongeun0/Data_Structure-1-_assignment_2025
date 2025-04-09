#include <stdio.h>
#include <stdlib.h>
#define NULL_ITEM (elementType) {-1, -1, -1}

//linearList.h����
//��� �� ��� ǥ��
typedef struct ElementType {
	int row;//��
	int col;//��
	int val;//�ش� ��ġ�� ��
}elementType;

//��������Ʈ
typedef struct ListType {
	int size;//����Ʈ �ִ� ũ��
	int last;//������ ���
	int move;// �׸� �̵� Ƚ��
	elementType* array;//��� �����ϴ� ���� �迭
}listType;

//linearList.c ����
//������ ũ���� ���ο� ����Ʈ ���� �Լ�
listType* createList(int size) {
	listType* lptr;
	lptr = (listType*)malloc(sizeof(listType));
	lptr->array = (elementType*)malloc(sizeof(elementType) * size);
	lptr->size = size;//�ִ� ũ�� ����
	lptr->last = -1;//�ʱ����: ��
	lptr->move = 0;//�̵� Ƚ�� �ʱ�ȭ
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

//��� �� ��� �Լ�
listType* addMatrix(listType* list1, listType* list2) {
	listType* result;
	elementType item;

	//����� ���� ũ���� ����Ʈ ����
	result = createList(list1->size + list2->size);

	//����� ��� ��� ����� ����(���1)
	for (int i = 0; i <= list1->last; i++) {
		item = readItem(list1, i);
		ordered_insertItem(result, item);
	}
	//���2 �� ��� ó��
	for (int i = 0; i <= list2->last; i++) {
		item = readItem(list2, i);
		
		//��� ���� ��� ã��
		int found = 0;
		for (int j = 0; j <= result->last; j++) {
			elementType existing = readItem(result, j);
			if (existing.row == item.row && existing.col == item.col) {
				//���� ��ġ�� ����
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

	//ù��° ��� �Է�
	matrix1 = createList(20);
	printf("����� �Է��Ͻÿ�? (-1�Է� �� ����� �Է��� �����)\n");

	while (1) {
		scanf_s("%d", &row);
		if (row == -1) break;
		scanf_s("%d %d", &col, &val);
		ordered_insertItem(matrix1, (elementType) { row, col, val });
	}

	//�ι�° ��� �Է�
	matrix2 = createList(20);
	printf("����� �Է��Ͻÿ�? (-1�Է� �� ����� �Է��� �����)\n");
	while (1) {
		scanf_s("%d", &row);
		if (row == -1) break;
		scanf_s("%d %d", &col, &val);
		ordered_insertItem(matrix2, (elementType) { row, col, val });
	}

	//�� ����� �� ���
	sum = addMatrix(matrix1, matrix2);

	printf("�� ����� ��\n");
	printList(sum);

	//�޸� ����
	free(matrix1->array);
	free(matrix1);
	free(matrix2->array);
	free(matrix2);
	free(sum->array);
	free(sum);

	return 0;
}