#include <stdio.h>
#include <stdlib.h>

#include "linearlist.h"

int main() {
	int i;
	char name[20];
	char num[20];
	int count;
	while (1) {
		printf("===== ��ȭ��ȣ�� �޴� =====\n");
		printf("1. ����ó �߰�\n");
		printf("2. ����ó ����\n");
		printf("3. ����ó �˻�\n");
		printf("4. ��ü ����ó ���\n");
		printf("0. ����\n");
		printf("�޴��� �����ϼ��� : ");
		scanf_s("%d", &i);

		switch (i)
		{
		case 0:
			printf("���� �Ǿ����ϴ�.");
			break;
		case 1:
			printf("\n�̸��� �Է��ϼ��� : ");
			scanf_s("%c");
			printf("\n��ȭ��ȣ�� �Է��ϼ��� : ");
			scanf_s("%c");
			count = i;
		case 2:
			printf("������ �̸��� �Է��ϼ��� : ");
			scanf_s("%c", &name);
			printf("\n���� �Ǿ����ϴ�.");
			count = i;
		case 3:
			printf("��ȭ��ȣ�� ã�� �̸��� �Է��ϼ��� : ");
			scanf_s("%c", &name);
		case 4:
			printf("----- ��ü ����ó -----\n");
			printf(printList);
		default:
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���");
			return;
		}
	}

	return 0;
}