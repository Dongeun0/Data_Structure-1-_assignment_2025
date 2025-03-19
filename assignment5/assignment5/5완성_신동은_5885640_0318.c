//����ü Calculator ����
//	add(int, int) : �� ������ ������ �����ϴ� �Լ� ������
//	sub(int, int) : �� ������ ������ �����ϴ� �Լ� ������
//	mul(int, int) : �� ������ ������ �����ϴ� �Լ� ������
//	div(int, int) : �� ������ �������� �����ϴ� �Լ� ������
//�� ����(+, -, *, / )�� �����ϴ� �Լ��� ����, Calculator ����ü�� �Լ� �����Ϳ� ����
//	add(int a, int b) : return a + b;
//	sub(int a, int b) : return a - b;
//	mul(int a, int b) : return a * b;
//	div(int a, int b) : return (b != 0) ? (double)a / b : 0;
//		������ ���꿡�� b == 0�� ��� 0�� ��ȯ�Ͽ� ���� ����
//�Է� �ܰ�
//	����ڷκ��� �� ���� ������ �Է¹���
//���� ���� �ܰ�
//	Calculator ����ü ����, ��Ģ���� �Լ� �����͸� ���� �����Ŵ
//	�Էµ� �� ������ �̿��Ͽ� ����ü�� �Լ� �����͸� ȣ���Ͽ� ���� ����
//��� �ܰ�
//	���� ����� ���� ���

#include <stdio.h>

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

int main() {
	//����ü ���� ����, �Լ� ������ �ʱ�ȭ
	Calculator cal = { add, sub, mul, div };

	//�� �ΰ��� ���� ����
	int i, j;

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

	return 0;
}