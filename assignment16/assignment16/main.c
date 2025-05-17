#include <stdio.h>
#include <stdlib.h>

#include "Linked List.h"

main() {

	linkedList_h* mylist;
	mylist = createLinkedList();

	int menu;
	elementType item;
	int position;
	listNode* pre;

	while (1) {
		printf("======= Linked_List Menu =======\n");
		printf("1) insertFirst   (리스트의 제일 앞에 삽입)\n");
		printf("2) insertLast    (리스트의 제일 뒤에 삽입)\n");
		printf("3) insertMiddle  (특정값 뒤에 삽입)\n");
		printf("4) insertNthNode (N번째 위치 삽입)\n");
		printf("6) deleteNode    (특정 값 삭제)\n");
		printf("7) print Head/Tail\n");
		printf("0) program Stop\n");
		printf("Select menu > ");
		scanf_s("%d", &menu);

		switch (menu)
		{
		case 1:
			printf("삽입할 값: ");
			scanf_s("%d", &item);
			insertFirstNode(mylist, item);
			printList(mylist);
			break;
		case 2:
			printf("삽입할 값: ");
			scanf_s("%d", &item);
			insertLastNode(mylist, item);
			printList(mylist);
			break;
		case 3:
			printf("(key) 어떤 값 뒤에? ");
			scanf_s("%d", &position);

			pre = mylist->head;
			while (pre != NULL && pre->data != position) {
				pre = pre->link;
			}

			if (pre == NULL) {
				printf("해당 값을 가진 노드를 찾을 수 없습니다.\n");
			}
			else {
				printf("삽입할 값: ");
				scanf_s("%d", &item);
				insertMiddleNode(mylist, pre, item);
				printList(mylist);
			}
			break;
		case 4:
			destroyLinkedList(mylist);
			printf("프로그램을 종료합니다.\n");
			return 0;
		case 6:
			destroyLinkedList(mylist);
			printf("프로그램을 종료합니다.\n");
			return 0;
		case 7:
			printHeadTail(mylist);
			break;
		case 0:
			destroyLinkedList(mylist);
			printf("프로그램을 종료합니다.\n");
			return 0;
		default:
			printf("잘못된 메뉴입니다. 다시 선택하여주십시오.\n");
			break;
		}
		printf("\n");
	}
	return 0;
}