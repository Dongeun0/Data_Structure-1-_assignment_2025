//�Լ� main :
//	int n, j, i
//	print "���� n�� �Է��ϼ���: "
//	scanf n
//
//	print "%d ������ �Ҽ�: (n������ ��)"
//
//	for ( i = 2; i <= n; i++) do :
//		prime = true
//
//		for (j = 2; j < i; j++) do :
//			if ( i % j == 0 ) then :
//				prime = false
//				break
//			end if
//		end for
//
//		if (prime == true) then:
//			print i
//		end if
//	end for
//
//	��ȯ 0
//end �Լ�

#include <stdio.h>

int main() {
	//���� ����
	int n, j;

	//���� n�Է� ����
	printf("���� n�� �Է��ϼ���: ");
	scanf_s("%d", &n);

	printf("%d ������ �Ҽ�: ", n);

	//2���� n���� ���� Ȯ��
	for (int i = 2; i <= n; i++) {
		//j�� i�� ��� ������Ű�鼭 ������ ���������� Ȯ��
		for (j = 2; j <= i; j++) {
			//������ �������� ����(�Ҽ��ƴ�)
			if (i % j == 0) {
				break;
			}
		}
		//i = j�� �Ҽ��� ��½�Ŵ
		if (i == j) {
			printf("%d ", i);
		}
	}

	return 0;
}