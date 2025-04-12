#include <stdio.h>
#include <stdlib.h>
#define Null_Item (elementType) {0, 0}

#include "LinearList.h"

listType* polymul(listType* poly1, listType* poly2) {
    listType* result = createList((poly1->last + 1) * (poly2->last + 1));

    // 모든 항끼리 곱하기
    for (int i = 0; i <= poly1->last; i++) {
        for (int j = 0; j <= poly2->last; j++) {
            elementType term1 = poly1->array[i];
            elementType term2 = poly2->array[j];

            // 새로운 항 생성
            int newCoef = term1.coef * term2.coef;
            int newExpo = term1.expo + term2.expo;

            // 같은 지수의 항이 있는지 확인
            int found = 0;
            for (int k = 0; k <= result->last; k++) {
                if (result->array[k].expo == newExpo) {
                    result->array[k].coef += newCoef;
                    found = 1;
                    break;
                }
            }

            // 같은 지수의 항이 없으면 새로 추가
            if (!found) {
                elementType newTerm = { newCoef, newExpo };
                ordered_insertItem(result, newTerm);
            }
        }
    }

    return result;
}

// 다항식 입력 함수
listType* inputPolynomial() {
    listType* poly = createList(10);
    int coef, expo;

    while (1) {
        if (scanf_s("%d", &coef) != 1) break;
        if (coef == 0) break;

        // 개행 처리
        while (getchar() != '\n'); // 버퍼 비우기 (숫자 바로 뒤에 입력된 공백/엔터 처리용)

        if (scanf_s("%d", &expo) != 1) break;

        elementType item = { coef, expo };
        ordered_insertItem(poly, item);
    }

    return poly;
}

int main() {
    listType* poly1, * poly2, * mul;

    // 첫 번째 다항식 입력
    printf("첫 번째 다항식을 입력하세요 (예: 3x^2+4x+1)\n");
    poly1 = inputPolynomial();

    // 두 번째 다항식 입력
    printf("두 번째 다항식을 입력하세요 (예: 2x^2+5x+3)\n");
    poly2 = inputPolynomial();

    // 다항식 곱셈 수행
    mul = polymul(poly1, poly2);

    // 결과 출력
    printf("\n[곱셈 결과]\n");
    printf("List: size = %d, last = %d, move = %d\n", mul->size, mul->last, mul->move);
    printf("Items: P(x) = ");

    // 다항식 출력
    for (int i = 0; i <= mul->last; i++) {
        if (i > 0 && mul->array[i].coef > 0) {
            printf("+");
        }

        if (mul->array[i].expo == 0) {
            printf("%d", mul->array[i].coef);
        }
        else if (mul->array[i].expo == 1) {
            printf("%dx", mul->array[i].coef);
        }
        else {
            printf("%dx^%d", mul->array[i].coef, mul->array[i].expo);
        }
    }
    printf("\n");

    // 메모리 해제
    destroyList(poly1);
    destroyList(poly2);
    destroyList(mul);

    return 0;
}