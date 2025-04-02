#include <stdio.h>
#include <stdlib.h>

int plus_count;

int fac_itr(int n) {
	int f = 1;
	for (int i = 1; i <= n; i++) {
		f = f * i;
	}
	return f;
}

int fac_rec(int n) {
	if (n == 1)
		return 1;
	else {
		return (n * fac_rec(n - 1));
	}
}

int fibo_itr(int n) {
	int f_n_2 = 0;
	int f_n_1 = 1;
	int f_n;
	
	for (int i = 2; i <= n; i++) {
		f_n = f_n_1 + f_n_2;
		f_n_2 = f_n_1;
		f_n_1 = f_n;
	}

	if (n == 0)
		return f_n_2;
	else if (n == 1)
		return f_n_1;
	else {
		return f_n;
		plus_count++;
	}
}

int fibo_recu(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1)
		return 1;
	else {
		return (fibo_recu(n - 1) + fibo_recu(n - 2));
		plus_count++;
	}
}
int main() {
	int m;
	printf("m? ");
	scanf_s("%d", &m);
	printf("%d! = %d by recursion\n", m, fac_rec(m));
	printf("%d! = %d by iterative\n", m, fac_itr(m));

	plus_count = 0;
	printf("f(%d) = %d by recursion(plus:%d)\n", m, fibo_recu(m), plus_count);
	plus_count = 0;
	printf("f(%d) = %d by iterative(plus:%d)\n", m, fibo_itr(m), plus_count);

	return 0;
}