#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// ===== ���� ADT =====
typedef struct {
	double data[MAX_STACK_SIZE];
	int top;
} Stack;

// ���� �ʱ�ȭ
void initStack(Stack* stack) {
	stack->top = -1;
}

// ������ ��� �ִ��� Ȯ��
int isEmpty(Stack* stack) {
	return stack->top == -1;
}

// ������ �� á���� Ȯ��
int isFull(Stack* stack) {
	return stack->top == MAX_STACK_SIZE - 1;
}

// ���ÿ� ��� �߰�
void push(Stack* stack, double value) {
	if (isFull(stack)) {
		printf("������ �� á���ϴ�!\n");
		exit(EXIT_FAILURE);
	}
	stack->data[++(stack->top)] = value;
}

// ���ÿ��� ��� ���� �� ��ȯ
double pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("������ ����ֽ��ϴ�!\n");
		exit(EXIT_FAILURE);
	}
	return stack->data[(stack->top)--];
}

// ������ top ��� Ȯ��
double peek(Stack* stack) {
	if (isEmpty(stack)) {
		printf("������ ����ֽ��ϴ�!\n");
		exit(EXIT_FAILURE);
	}
	return stack->data[stack->top];
}

//��Ģ ������ �����ϴ� ����ü ����
typedef struct {
	int (*add)(int, int);
	int (*sub)(int, int);
	int (*mul)(int, int);
	double (*div)(int, int);
}Calculator;

//�� ��Ģ ���� �Լ� ����
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
double div(int a, int b) { return (b != 0) ? (double)a / b : 0; }

//�Էµ� ���� Ÿ�Կ� ���� ���� �ٸ� ��� ����
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
	//����ü ���� ����, �Լ� ������ �ʱ�ȭ
	Calculator cal = { add, sub, mul, div };

	//�� �ΰ��� ���� ����
	int i, j;
	char type;

	//�� ���� �Է�
	printf("ù ��° ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &i);
	printf("�� ��° ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &j);

	//�� ��Ģ���� ��� ���
	printf("���� : %d\n", cal.add(i, j));
	printf("���� : %d\n", cal.sub(i, j));
	printf("���� : %d\n", cal.mul(i, j));
	printf("������ : %.2f\n", cal.div(i, j));

	//�ι�° �� ������ ���� Ÿ�� �Է�
	printf("����� ������ �Է��ϼ��� (��: 3 + 5 * 2 - 8 / 4): ");
	scanf_s("%d %c %d", &i, &type, &j);

	//�Ŀ� ���� ��ü ��� ��� ���
	printf("���: &lf\n", cal2);

	return 0;
}