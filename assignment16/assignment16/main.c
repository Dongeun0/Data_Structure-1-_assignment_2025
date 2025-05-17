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
		printf("1) insertFirst   (����Ʈ�� ���� �տ� ����)\n");
		printf("2) insertLast    (����Ʈ�� ���� �ڿ� ����)\n");
		printf("3) insertMiddle  (Ư���� �ڿ� ����)\n");
		printf("4) insertNthNode (N��° ��ġ ����)\n");
		printf("6) deleteNode    (Ư�� �� ����)\n");
		printf("7) print Head/Tail\n");
		printf("0) program Stop\n");
		printf("Select menu > ");
		scanf_s("%d", &menu);

		switch (menu)
		{
		case 1:
			printf("������ ��: ");
			scanf_s("%d", &item);
			insertFirstNode(mylist, item);
			printList(mylist);
			break;
		case 2:
			printf("������ ��: ");
			scanf_s("%d", &item);
			insertLastNode(mylist, item);
			printList(mylist);
			break;
		case 3:
			printf("(key) � �� �ڿ�? ");
			scanf_s("%d", &position);

			pre = mylist->head;
			while (pre != NULL && pre->data != position) {
				pre = pre->link;
			}

			if (pre == NULL) {
				printf("�ش� ���� ���� ��带 ã�� �� �����ϴ�.\n");
			}
			else {
				printf("������ ��: ");
				scanf_s("%d", &item);
				insertMiddleNode(mylist, pre, item);
				printList(mylist);
			}
			break;
		case 4:
			destroyLinkedList(mylist);
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		case 6:
			destroyLinkedList(mylist);
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		case 7:
			printHeadTail(mylist);
			break;
		case 0:
			destroyLinkedList(mylist);
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		default:
			printf("�߸��� �޴��Դϴ�. �ٽ� �����Ͽ��ֽʽÿ�.\n");
			break;
		}
		printf("\n");
	}
	return 0;
}