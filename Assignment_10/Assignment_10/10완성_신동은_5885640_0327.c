#include <stdio.h>
#include <stdlib.h>

int main() {
	//���� �� ����
	int a = 2;
	int b = 2;
	//2���� �迭 ���� �Ҵ�
	int** Arr = (int**)malloc(sizeof(int*)*a);
	int** arr = (int**)malloc(sizeof(int*)*a);

	//�࿡ ���� �޸� �Ҵ�
	for (int i = 0; i < a; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * b);
		arr[i] = (int*)malloc(sizeof(int) * b);
	}

	printf("ù ��° 2x2 ��� �Է�: \n");
	//�Է��� ������ �迭�� �� ��ġ�� ����
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%2d", &Arr[i][j]);
		}
	}

	printf("�� ��° 2x2 ��� �Է�: \n");
	//�Է��� ������ �迭�� �� ��ġ�� ����
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%2d", &arr[i][j]);
		}
	}

	printf("��� ���� ���: \n");
	//�� �迭�� ��ġ�� �ִ� �������� ���� ����ϰ� ��ġ�� �°� �ٽ� �����
	for (int i = 0; i < 2; i++) {
		//�� ��ġ���� �� �迭�� ���� �ڸ��� �ִ� �������� ���ϰ� ���
		for (int j = 0; j < 2; j++) {
			int sum = Arr[i][j] + arr[i][j];
			printf("%2d", sum);
		}
		printf("\n");
	}
	free(Arr);
	free(arr);
	return 0;
}