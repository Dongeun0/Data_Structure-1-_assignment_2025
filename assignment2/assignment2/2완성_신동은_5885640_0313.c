#include <stdio.h>
#include <string.h>

void main() {
	//입력 받을 실수
	float num;
	//float 비트 패턴 저장할 변수
	unsigned int n;

	//실수 입력 + 저장
	printf("실수를 입력하세요: ");
	scanf_s("%f", &num);

	//foat의 비트 패턴을 unsigned int로 변환
	//input 변수의 주소를 unsigned int 포인터로 형변환 후 값 가져옴
	n = *(unsigned int*)&num;

	//31번째 비트 오른쪽으로 이동해서 제일 앞쪽에 부호 비트 가져옴
	unsigned int b = (n >> 31) & 1;
	//23번째 비트 오른쪽으로 이동해서 하위 지수 비트 8개 가져옴
	unsigned int g = (n >> 23) & 0xFF;
	// 하위 나머지 가수 비트 가져옴
	unsigned int ga = n & 0x7FFFFF;

	//부호비트 출력
	printf("부호 (1비트) : %u\n", b);

	//지수 비트 출력
	printf("지수 (8비트) : ");
	for (int i = 7; i >= 0; i--) {
		//i번 오른쪽으로 이동 후 하위 1비트 가져옴
		printf("%d ", (g >> i) & 1);
	}
	printf("\n");

	//가수 비트 출력
	printf("가수 (23비트) : ");
	for (int i = 22; i >= 0; i--) {
		//i번 오른쪽으로 이동 후 하위 1비트 가져옴
		printf("%d ", (ga >> i) & 1);
	}
	printf("\n");

	return 0;
}