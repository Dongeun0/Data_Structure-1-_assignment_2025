#include <stdio.h>
#include <string.h>

int main() {
	//���ڿ��� ������ �迭 ����
	char n[100];

	//���ڿ� �Է� �ޱ�
	printf("���ڿ��� �Է��ϼ��� : ");
	//�ٹٲ��� ������ ������ �Է� �ް� sizeof�� �Է� ũ�⸦ ������ ���� �����÷ο� ����
	scanf_s("%[^\n]", n, sizeof(n));

	//�Է� ���� ���ڿ� ���� ���
	int len = strlen(n);
	printf("���ڿ��� ���� : %d\n", len);


	printf("��ȯ�� ���ڿ�: ");

	//���ڿ� ���̸�ŭ �ݺ�
	for (int i = 0; i < len; i++) {
		char n1 = n[i];//���� �ϳ��ϳ� ��������

		//�빮��-> �ҹ��� ��ȯ
		if (n1 >= 'A' && n1 <= 'Z') {
			printf("%c", n1 + ('a' - 'A'));
		}
		//�ҹ���-> �빮�� ��ȯ
		else if (n1 >= 'a' && n1 <= 'z') {
			printf("%c", n1 - ('a' - 'A'));
		}
		//���ĺ��� �ƴ� ���ڵ��� �״�� ���
		else {
			printf("%c", n1);
		}
	}

	return 0;
}