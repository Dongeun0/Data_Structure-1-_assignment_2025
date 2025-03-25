/*
Function main()
	Arr[2][2]:
	arr[2][2]:

	Print "첫 번째 2x2 행렬 입력: "
	For (i=0; i<2; i++) do
		For(j=0; j<2; j++) do
			Get Arr[i][j]:
		End For
	End For

	Print "두 번째 2x2 행렬 입력: "
	For (i=0; i<2; i++) do
		For(j=0; j<2; j++) do
			Get arr[i][j]:
		End For
	End For

	Print "행렬 덧셈 결과: "
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
	int Arr[2][2];
	int arr[2][2];

	printf("첫 번째 2x2 행렬 입력: \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%2d", &Arr[i][j]);
		}
	}

	printf("두 번째 2x2 행렬 입력: \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%2d", &arr[i][j]);
		}
	}

	printf("행렬 덧셈 결과: \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int sum = Arr[i][j] + arr[i][j];
			printf("%2d", sum);
		}
		printf("\n");
	}

	return 0;
}