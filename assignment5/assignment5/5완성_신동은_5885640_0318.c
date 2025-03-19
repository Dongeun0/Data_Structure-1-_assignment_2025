//구조체 Calculator 정의
//	add(int, int) : 두 정수의 덧셈을 수행하는 함수 포인터
//	sub(int, int) : 두 정수의 뺄셈을 수행하는 함수 포인터
//	mul(int, int) : 두 정수의 곱셈을 수행하는 함수 포인터
//	div(int, int) : 두 정수의 나눗셈을 수행하는 함수 포인터
//각 연산(+, -, *, / )을 수행하는 함수를 구현, Calculator 구조체의 함수 포인터와 연결
//	add(int a, int b) : return a + b;
//	sub(int a, int b) : return a - b;
//	mul(int a, int b) : return a * b;
//	div(int a, int b) : return (b != 0) ? (double)a / b : 0;
//		나눗셈 연산에서 b == 0인 경우 0을 반환하여 오류 방지
//입력 단계
//	사용자로부터 두 개의 정수를 입력받음
//연산 수행 단계
//	Calculator 구조체 선언, 사칙연산 함수 포인터를 각각 연결시킴
//	입력된 두 정수를 이용하여 구조체의 함수 포인터를 호출하여 연산 수행
//출력 단계
//	연산 결과를 각각 출력

#include <stdio.h>

//사칙 연산을 진행하는 구조체 정의
typedef struct {
	int (*add)(int, int);
	int (*sub)(int, int);
	int (*mul)(int, int);
	double (*div)(int, int);
}Calculator;

//각 사칙 연산 함수 정의
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
double div(int a, int b) { return (b != 0) ? (double)a / b : 0; }

int main() {
	//구조체 변수 선언, 함수 포인터 초기화
	Calculator cal = { add, sub, mul, div };

	//각 두개의 정수 선언
	int i, j;

	//두 정수 입력
	printf("첫 번째 양의 정수를 입력하세요: ");
	scanf_s("%d", &i);
	printf("두 번째 양의 정수를 입력하세요: ");
	scanf_s("%d", &j);

	//각 사칙연산 결과 출력
	printf("덧셈 : %d\n", cal.add(i, j));
	printf("뺄셈 : %d\n", cal.sub(i, j));
	printf("곱셈 : %d\n", cal.mul(i, j));
	printf("나눗셈 : %.2f\n", cal.div(i, j));

	return 0;
}