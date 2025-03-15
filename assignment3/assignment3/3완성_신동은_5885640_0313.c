#include <stdio.h>
#include <string.h>

int main() {
	//문자열을 저장할 배열 선언
	char n[100];

	//문자열 입력 받기
	printf("문자열을 입력하세요 : ");
	//줄바꿈을 만나기 전까지 입력 받고 sizeof로 입력 크기를 제한해 버퍼 오버플로우 방지
	scanf_s("%[^\n]", n, sizeof(n));

	//입력 받은 문자열 길이 출력
	int len = strlen(n);
	printf("문자열의 길이 : %d\n", len);


	printf("변환된 문자열: ");

	//문자열 길이만큼 반복
	for (int i = 0; i < len; i++) {
		char n1 = n[i];//문자 하나하나 가져오기

		//대문자-> 소문자 변환
		if (n1 >= 'A' && n1 <= 'Z') {
			printf("%c", n1 + ('a' - 'A'));
		}
		//소문자-> 대문자 변환
		else if (n1 >= 'a' && n1 <= 'z') {
			printf("%c", n1 - ('a' - 'A'));
		}
		//알파벳이 아닌 문자들은 그대로 출력
		else {
			printf("%c", n1);
		}
	}

	return 0;
}