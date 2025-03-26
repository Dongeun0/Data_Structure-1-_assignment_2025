/*
Function Main start
	Get a
	Print "정수의 개수를 입력하세요: "
	Scanf a

	arr = 동적 할당

	Print " %d개의 정수를 입력하세요: \n", a

	If (arr = NULL) then
		Print "메모리 할당 실패"
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

	Print "오름차순으로 정렬된 정수들: "
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

	printf("정수의 개수를 입력하세요: ");
	scanf_s("%d", &a);

	//개수 저장할 동적 메모리 할당
	int* arr = malloc(sizeof(int)*a);

	printf("%d개의 정수를 입력하세요: \n", a);

	//메모리 할당 실패하면 에러 안내 후 종료
	if (arr == NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}

	//a개의 정수를 입력 받음
	for (int i = 0; i < a; i++) {
		scanf_s("%d ", &arr[i]);
	}

	for (int i = 0; i < a-1; i++) {
		//i를 최소값으로 초기화
		int min = i;
		//i번째 이후 검사로 최소값을 찾음
		for (int j = i + 1; j < a; j++) {
			//만약 더 작은 최소값을 찾으면 그 값으로 변경
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		//최소값이 현재값과 다르면 교환
		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	//정렬된 정수 출력
	printf("오름차순으로 정렬된 정수들: ");
	for (int i = 0; i < a; i++) {
		printf("%d ", arr[i]);
	}

	//메모리 해제
	free(arr);
	return 0;
}