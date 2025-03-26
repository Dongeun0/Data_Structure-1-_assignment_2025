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
	//각 첫번째 배열과 두번째 배열 저장
	int Arr[2][2];
	int arr[2][2];

	printf("첫 번째 2x2 행렬 입력: \n");
	//입력한 정수를 배열의 각 위치에 저장
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%2d", &Arr[i][j]);
		}
	}

	printf("두 번째 2x2 행렬 입력: \n");
	//입력한 정수를 배열의 각 위치에 저장
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%2d", &arr[i][j]);
		}
	}

	printf("행렬 덧셈 결과: \n");
	//두 배열에 위치에 있는 정수들의 합을 계산하고 위치에 맞게 다시 출력함
	for (int i = 0; i < 2; i++) {
		//각 위치마다 두 배열에 같은 자리에 있는 정수들을 더하고 출력
		for (int j = 0; j < 2; j++) {
			int sum = Arr[i][j] + arr[i][j];
			printf("%2d", sum);
		}
		printf("\n");
	}

	return 0;
}