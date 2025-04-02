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
		printf("�Ǻ���ġ ���� ��� ���� (1: �����, 2: ��ȯ��, 0: ����): ");
		scanf_s("%d", &i);

		if (i == 0) {
			printf("���α׷��� ����Ǿ����ϴ�.\n");
			break;
		}
		switch (i) {
		case 1:
			printf("���� N�� �Է��ϼ��� (�����Ϸ��� 0 �Է�): ");
			scanf_s("%d", &j);
			if (j == 0) {
				continue;
			}
			printf("F(%d) = %d (����� ���)\n", j, fibo_rec(j));
			break;
		case 2:
			printf("���� N�� �Է��ϼ��� (�����Ϸ��� 0 �Է�): ");
			scanf_s("%d", &j);
			if (j == 0) {
				continue;
			}
			printf("F(%d) = %d (��ȯ�� ���)\n", j, fibo_itr(j));
			break;
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
		}
	}
	return 0;
}