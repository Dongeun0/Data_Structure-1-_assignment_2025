#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// ===== 스택 ADT =====
typedef struct {
	double data[MAX_STACK_SIZE];
	int top;
} Stack;

// 스택 초기화
void initStack(Stack* stack) {
	stack->top = -1;
}

// 스택이 비어 있는지 확인
int isEmpty(Stack* stack) {
	return stack->top == -1;
}

// 스택이 꽉 찼는지 확인
int isFull(Stack* stack) {
	return stack->top == MAX_STACK_SIZE - 1;
}

// 스택에 요소 추가
void push(Stack* stack, double value) {
	if (isFull(stack)) {
		printf("스택이 꽉 찼습니다!\n");
		exit(EXIT_FAILURE);
	}
	stack->data[++(stack->top)] = value;
}

// 스택에서 요소 제거 및 반환
double pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("스택이 비어있습니다!\n");
		exit(EXIT_FAILURE);
	}
	return stack->data[(stack->top)--];
}

// 스택의 top 요소 확인
double peek(Stack* stack) {
	if (isEmpty(stack)) {
		printf("스택이 비어있습니다!\n");
		exit(EXIT_FAILURE);
	}
	return stack->data[stack->top];
}

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

//입력된 연산 타입에 따른 각각 다른 계산 정의
double cal2(int a, char type, int b) {
	switch (type) {
		case '+': a + b;
		case '-': a - b;
		case '*': a * b;
		case '/': a / b; break;
		default:
			return 0;
	}
}

int main() {
	//구조체 변수 선언, 함수 포인터 초기화
	Calculator cal = { add, sub, mul, div };

	//각 두개의 정수 선언
	int i, j;
	char type;

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

	//두번째 두 정수와 연산 타입 입력
	printf("계산할 수식을 입력하세요 (예: 3 + 5 * 2 - 8 / 4): ");
	scanf_s("%d %c %d", &i, &type, &j);

	//식에 따른 전체 계산 결과 출력
	printf("결과: &lf\n", cal2);

	return 0;
}