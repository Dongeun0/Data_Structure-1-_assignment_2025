#include <stdio.h>
#include <string.h>

void main() {
	//�Է� ���� �Ǽ�
	float num;
	//float ��Ʈ ���� ������ ����
	unsigned int n;

	//�Ǽ� �Է� + ����
	printf("�Ǽ��� �Է��ϼ���: ");
	scanf_s("%f", &num);

	//foat�� ��Ʈ ������ unsigned int�� ��ȯ
	//input ������ �ּҸ� unsigned int �����ͷ� ����ȯ �� �� ������
	n = *(unsigned int*)&num;

	//31��° ��Ʈ ���������� �̵��ؼ� ���� ���ʿ� ��ȣ ��Ʈ ������
	unsigned int b = (n >> 31) & 1;
	//23��° ��Ʈ ���������� �̵��ؼ� ���� ���� ��Ʈ 8�� ������
	unsigned int g = (n >> 23) & 0xFF;
	// ���� ������ ���� ��Ʈ ������
	unsigned int ga = n & 0x7FFFFF;

	//��ȣ��Ʈ ���
	printf("��ȣ (1��Ʈ) : %u\n", b);

	//���� ��Ʈ ���
	printf("���� (8��Ʈ) : ");
	for (int i = 7; i >= 0; i--) {
		//i�� ���������� �̵� �� ���� 1��Ʈ ������
		printf("%d ", (g >> i) & 1);
	}
	printf("\n");

	//���� ��Ʈ ���
	printf("���� (23��Ʈ) : ");
	for (int i = 22; i >= 0; i--) {
		//i�� ���������� �̵� �� ���� 1��Ʈ ������
		printf("%d ", (ga >> i) & 1);
	}
	printf("\n");

	return 0;
}