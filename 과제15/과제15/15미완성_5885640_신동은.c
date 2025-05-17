#include <stdio.h>
#include <stdlib.h>

#include "linearlist.h"

int main() {
	int i;
	char name[20];
	char num[20];
	int count;
	while (1) {
		printf("===== 전화번호부 메뉴 =====\n");
		printf("1. 연락처 추가\n");
		printf("2. 연락처 삭제\n");
		printf("3. 연락처 검색\n");
		printf("4. 전체 연락처 출력\n");
		printf("0. 종료\n");
		printf("메뉴를 선택하세요 : ");
		scanf_s("%d", &i);

		switch (i)
		{
		case 0:
			printf("종료 되었습니다.");
			break;
		case 1:
			printf("\n이름을 입력하세요 : ");
			scanf_s("%c");
			printf("\n전화번호를 입력하세요 : ");
			scanf_s("%c");
			count = i;
		case 2:
			printf("삭제할 이름을 입력하세요 : ");
			scanf_s("%c", &name);
			printf("\n삭제 되었습니다.");
			count = i;
		case 3:
			printf("전화번호를 찾을 이름을 입력하세요 : ");
			scanf_s("%c", &name);
		case 4:
			printf("----- 전체 연락처 -----\n");
			printf(printList);
		default:
			printf("잘못 입력하셨습니다. 다시 입력해주세요");
			return;
		}
	}

	return 0;
}