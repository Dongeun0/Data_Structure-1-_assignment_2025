#include <stdio.h>
#include <stdlib.h>

int main() {
	//열과 행 선언
	int a = 2;
	int b = 2;
	//2개의 배열 동적 할당
	int** Arr = (int**)malloc(sizeof(int*)*a);
	int** arr = (int**)malloc(sizeof(int*)*a);

	//행에 대해 메모리 할당
	for (int i = 0; i < a; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * b);
		arr[i] = (int*)malloc(sizeof(int) * b);
	}

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
	free(Arr);
	free(arr);
	return 0;
}