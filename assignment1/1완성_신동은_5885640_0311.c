#include <stdio.h>

void main() {
	int j, i;
	printf("정수를 입력하세요: ");

	// 정수 j 입력 받기.
	scanf_s("%d", &j);

	// 입력 받은 정수가 0일 때 오류로 판단
	if (j == 0) {
		printf("프로그램을 종료합니다");
	}
	//입력 받은 정수의 32비트 표현, 오른쪽으로 한칸씩 이동하면서 비트안 0또는 1을 채움.
	else {
		printf("입력된 정수의 32비트 표현: ");
		for (i = 31; i >= 0; i--) {
			printf("%d", (j >> i) & 1);
		}
	}
	return 0;
}