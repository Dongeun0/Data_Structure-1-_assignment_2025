#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, temp;

	printf("������ ������ �Է��ϼ���: ");
	scanf_s("%d", &a);
	int* arr = malloc(sizeof(int)*a);
	if (arr != NULL) {
		printf("%d���� ������ �Է��ϼ���: \n", a);
		for (int i = 0; i < a; i++) {
			scanf_s("%d ", arr + i);
		}
		scanf_s("%[^\n]s", a);
		fflush(stdin);
		printf("������������ ���ĵ� ������: ");
		for (int i = 0; i < a; i++) {
			for (int j = i + 1;j < a; j++) {
				if (arr[j] < arr[i]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		for (int i = 0; i < a; i++) {
			printf("%d ", arr[i]);
		}
		free(a);
	}
	return 0;
}