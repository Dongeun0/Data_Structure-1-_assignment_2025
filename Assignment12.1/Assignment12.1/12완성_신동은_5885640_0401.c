#include <stdio.h>
#include <stdlib.h>

int fibo_rec(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return (fibo_rec(n - 1) + fibo_rec(n - 2));
	}
}

int fibo_itr(int n) {
	int f_2 = 0;
	int f_1 = 1;
	int f = 0;

	for (int i = 2; i <= n; i++) {
		f = f_1 + f_2;
		f_2 = f_1;
		f_1 = f;
	}

	if (n == 0) return f_2;
	else if (n == 1) return f_1;
	else return f;
}

int main() {
	int i;
	int j = 0;

	while (1) {
		printf("피보나치 수열 방법 선택 (1: 재귀적, 2: 순환적, 0: 종료): ");
		scanf_s("%d", &i);

		if (i == 0) {
			printf("프로그램이 종료되었습니다.\n");
			break;
		}
		switch (i) {
		case 1:
			printf("정수 N을 입력하세요 (종료하려면 0 입력): ");
			scanf_s("%d", &j);
			if (j == 0) {
				continue;
			}
			printf("F(%d) = %d (재귀적 방법)\n", j, fibo_rec(j));
			break;
		case 2:
			printf("정수 N을 입력하세요 (종료하려면 0 입력): ");
			scanf_s("%d", &j);
			if (j == 0) {
				continue;
			}
			printf("F(%d) = %d (순환적 방법)\n", j, fibo_itr(j));
			break;
		default:
			printf("잘못된 선택입니다. 다시 선택해주세요.\n");
		}
	}
	return 0;
}