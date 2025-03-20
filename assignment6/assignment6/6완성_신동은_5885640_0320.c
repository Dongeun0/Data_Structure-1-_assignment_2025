/*
메인 함수 start
	정수 n, j, i를 선언
	print "정수 n을 입력하세요: "
	get n

	print "n이하의 소수 : "(입력된 정수 n)

	for i = 2 to n do
		for j = 2 to i do
			if i % j == 0 then
				out
			end if
		end for
		if i == j then
			print i
		end if
	end for
end 메인 함수


빅-오 예측
시간 복잡도는 O(n^2). 외부 for문은 n-1번에 비례하는 횟수만큼 실행
내부 for문은 외부 for문의 각 i값에 대해 실행되는 횟수가 달라짐. i = 2일 때 1번, 3일 때 2번 --- n일 때 n-1번을 통해 횟수는 1 + 2 + 3 + ... + (n-1)번.
따라서 (n-1) * n / 2.
빅 오 표기법에서 최고차항이 n^2이므로 복잡도는 O(n^2)로 예측 가능
*/

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