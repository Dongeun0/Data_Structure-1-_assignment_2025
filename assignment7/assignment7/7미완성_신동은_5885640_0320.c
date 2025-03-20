/*
����ü Calculator ����:
  �Լ� ������ add(����, ����)
  �Լ� ������ sub(����, ����)
  �Լ� ������ mul(����, ����)
  �Լ� ������ div(����, ����)

�Լ� add(���� a, ���� b):
  return a + b

�Լ� sub(���� a, ���� b):
  return a - b

�Լ� mul(���� a, ���� b):
  return a * b

�Լ� div(���� a, ���� b):
  if b != 0 then:
	return (a / b)
  else:
	return 0

�Լ� cal2(���� a, ���� type, ���� b):
  switch (type):
	case '+':
	  a + b 
	case '-':
	  a - b 
	case '*':
	  a * b 
	case '/':
	  a / b 
	  break
	default:
	  return 0

���� �Լ� start:
  Calculator cal
  cal.add = �Լ� add
  cal.sub = �Լ� sub
  cal.mul = �Լ� mul
  cal.div = �Լ� div

  ���� i, j ����:
  ���� type ����:

  print "ù ��° ���� ������ �Է��ϼ���: "
  get i
  print "�� ��° ���� ������ �Է��ϼ���: "
  get j

  print "���� : ", cal.add(i, j)
  print "���� : ", cal.sub(i, j)
  print "���� : ", cal.mul(i, j)
  print "������ : ", cal.div(i, j) (�Ҽ��� �� �ڸ����� ǥ��)

  print "����� ������ �Է��ϼ��� (��: 3 + 5 * 2 - 8 / 4): "
  get i, type, j

  print "���: ", cal2
end ���� �Լ�
*/

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

//�Էµ� ���� Ÿ�Կ� ���� ���� �ٸ� ��� ����
/*
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
*/

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
	/*
	printf("����� ������ �Է��ϼ��� (��: 3 + 5 * 2 - 8 / 4): ");
	scanf_s("%d %c %d", &i, &type, &j);

	//�Ŀ� ���� ��ü ��� ��� ���
	printf("���: &lf\n", cal2);
	*/
	return 0;
}