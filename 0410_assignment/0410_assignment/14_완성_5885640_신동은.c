#include <stdio.h>
#include <stdlib.h>
#define Null_Item (elementType) {0, 0}

#include "LinearList.h"

listType* polymul(listType* poly1, listType* poly2) {
    listType* result = createList((poly1->last + 1) * (poly2->last + 1));

    // ��� �׳��� ���ϱ�
    for (int i = 0; i <= poly1->last; i++) {
        for (int j = 0; j <= poly2->last; j++) {
            elementType term1 = poly1->array[i];
            elementType term2 = poly2->array[j];

            // ���ο� �� ����
            int newCoef = term1.coef * term2.coef;
            int newExpo = term1.expo + term2.expo;

            // ���� ������ ���� �ִ��� Ȯ��
            int found = 0;
            for (int k = 0; k <= result->last; k++) {
                if (result->array[k].expo == newExpo) {
                    result->array[k].coef += newCoef;
                    found = 1;
                    break;
                }
            }

            // ���� ������ ���� ������ ���� �߰�
            if (!found) {
                elementType newTerm = { newCoef, newExpo };
                ordered_insertItem(result, newTerm);
            }
        }
    }

    return result;
}

// ���׽� �Է� �Լ�
listType* inputPolynomial() {
    listType* poly = createList(10);
    int coef, expo;

    while (1) {
        if (scanf_s("%d", &coef) != 1) break;
        if (coef == 0) break;

        // ���� ó��
        while (getchar() != '\n'); // ���� ���� (���� �ٷ� �ڿ� �Էµ� ����/���� ó����)

        if (scanf_s("%d", &expo) != 1) break;

        elementType item = { coef, expo };
        ordered_insertItem(poly, item);
    }

    return poly;
}

int main() {
    listType* poly1, * poly2, * mul;

    // ù ��° ���׽� �Է�
    printf("ù ��° ���׽��� �Է��ϼ��� (��: 3x^2+4x+1)\n");
    poly1 = inputPolynomial();

    // �� ��° ���׽� �Է�
    printf("�� ��° ���׽��� �Է��ϼ��� (��: 2x^2+5x+3)\n");
    poly2 = inputPolynomial();

    // ���׽� ���� ����
    mul = polymul(poly1, poly2);

    // ��� ���
    printf("\n[���� ���]\n");
    printf("List: size = %d, last = %d, move = %d\n", mul->size, mul->last, mul->move);
    printf("Items: P(x) = ");

    // ���׽� ���
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

    // �޸� ����
    destroyList(poly1);
    destroyList(poly2);
    destroyList(mul);

    return 0;
}