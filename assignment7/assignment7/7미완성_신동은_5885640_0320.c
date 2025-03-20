/*
구조체 Calculator 정의:
  함수 포인터 add(정수, 정수)
  함수 포인터 sub(정수, 정수)
  함수 포인터 mul(정수, 정수)
  함수 포인터 div(정수, 정수)

함수 add(정수 a, 정수 b):
  return a + b

함수 sub(정수 a, 정수 b):
  return a - b

함수 mul(정수 a, 정수 b):
  return a * b

함수 div(정수 a, 정수 b):
  if b != 0 then:
	return (a / b)
  else:
	return 0

함수 cal2(정수 a, 문자 type, 정수 b):
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

메인 함수 start:
  Calculator cal
  cal.add = 함수 add
  cal.sub = 함수 sub
  cal.mul = 함수 mul
  cal.div = 함수 div

  정수 i, j 선언:
  문자 type 선언:

  print "첫 번째 양의 정수를 입력하세요: "
  get i
  print "두 번째 양의 정수를 입력하세요: "
  get j

  print "덧셈 : ", cal.add(i, j)
  print "뺄셈 : ", cal.sub(i, j)
  print "곱셈 : ", cal.mul(i, j)
  print "나눗셈 : ", cal.div(i, j) (소수점 두 자리까지 표시)

  print "계산할 수식을 입력하세요 (예: 3 + 5 * 2 - 8 / 4): "
  get i, type, j

  print "결과: ", cal2
end 메인 함수
*/

#include <stdio.h>

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
	/*
	printf("계산할 수식을 입력하세요 (예: 3 + 5 * 2 - 8 / 4): ");
	scanf_s("%d %c %d", &i, &type, &j);

	//식에 따른 전체 계산 결과 출력
	printf("결과: &lf\n", cal2);
	*/
	return 0;
}