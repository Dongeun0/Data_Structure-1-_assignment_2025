//함수 main :
//	int n, j, i
//	print "정수 n을 입력하세요: "
//	scanf n
//
//	print "%d 이하의 소수: (n이하의 값)"
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
//	반환 0
//end 함수

#include <stdio.h>

int main() {
	//정수 선언
	int n, j;

	//정수 n입력 받음
	printf("정수 n을 입력하세요: ");
	scanf_s("%d", &n);

	printf("%d 이하의 소수: ", n);

	//2부터 n까지 정수 확인
	for (int i = 2; i <= n; i++) {
		//j를 i랑 계속 증가시키면서 나누어 떨어지는지 확인
		for (j = 2; j <= i; j++) {
			//나누어 떨어지면 나감(소수아님)
			if (i % j == 0) {
				break;
			}
		}
		//i = j면 소수라서 출력시킴
		if (i == j) {
			printf("%d ", i);
		}
	}

	return 0;
}