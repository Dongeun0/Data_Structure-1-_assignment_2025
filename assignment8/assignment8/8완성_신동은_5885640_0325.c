/*
Function main()
	Arr[2][2]:
	arr[2][2]:

	Print "ù ��° 2x2 ��� �Է�: "
	For (i=0; i<2; i++) do
		For(j=0; j<2; j++) do
			Get Arr[i][j]:
		End For
	End For

	Print "�� ��° 2x2 ��� �Է�: "
	For (i=0; i<2; i++) do
		For(j=0; j<2; j++) do
			Get arr[i][j]:
		End For
	End For

	Print "��� ���� ���: "
	For (i=0; i<2; i++) do
		For(j=0; j<2; j++) do
			sum = Arr[i][j]+arr[i][j]:
			Print sum
		End For
		Print \n
	End For
End main function
*/

#include <stdio.h>

int main() {
	//�� ù��° �迭�� �ι�° �迭 ����
	int Arr[2][2];
	int arr[2][2];

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

	return 0;
}