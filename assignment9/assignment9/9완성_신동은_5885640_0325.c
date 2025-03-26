/*
Function Main start
	Get a
	Print "������ ������ �Է��ϼ���: "
	Scanf a

	arr = ���� �Ҵ�

	Print " %d���� ������ �Է��ϼ���: \n", a

	If (arr = NULL) then
		Print "�޸� �Ҵ� ����"
		Return 1
	End if

	For (i = 0; i < a; i++) do
		Scanf arr[i]
	End for

	For (i = 0; i < a-1; i++) do
		min = i
		For (j = i + 1; j < a; j++) do
			If (arr[j] < arr[min]) then
				min = j
			End if
		End for

		If (min != i) then
			temp = arr[i]
			arr[i] = arr[min]
			arr[min] = temp
		End if
	End for

	Print "������������ ���ĵ� ������: "
	For (i = 0; i < a; i++) do
		Print"%d ", arr[i];
	End For

	free arr
End Main
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int a;

	printf("������ ������ �Է��ϼ���: ");
	scanf_s("%d", &a);

	//���� ������ ���� �޸� �Ҵ�
	int* arr = malloc(sizeof(int)*a);

	printf("%d���� ������ �Է��ϼ���: \n", a);

	//�޸� �Ҵ� �����ϸ� ���� �ȳ� �� ����
	if (arr == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}

	//a���� ������ �Է� ����
	for (int i = 0; i < a; i++) {
		scanf_s("%d ", &arr[i]);
	}

	for (int i = 0; i < a-1; i++) {
		//i�� �ּҰ����� �ʱ�ȭ
		int min = i;
		//i��° ���� �˻�� �ּҰ��� ã��
		for (int j = i + 1; j < a; j++) {
			//���� �� ���� �ּҰ��� ã���� �� ������ ����
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		//�ּҰ��� ���簪�� �ٸ��� ��ȯ
		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	//���ĵ� ���� ���
	printf("������������ ���ĵ� ������: ");
	for (int i = 0; i < a; i++) {
		printf("%d ", arr[i]);
	}

	//�޸� ����
	free(arr);
	return 0;
}