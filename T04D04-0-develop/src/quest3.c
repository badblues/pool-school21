#include <stdio.h>

long int fibonacci(int a) {
    if (a == 0) return 0;
	if ((a == 1) || (a == 2))
		return 1;
	return fibonacci(a - 1) + fibonacci(a - 2);
}

int main() {
	int a;
	scanf("%d", &a);\
    if (a < 0) {
        printf("n/a");
        return 1;
    }
	printf("%ld", fibonacci(a));
	return 0;
}
