#include <stdio.h>

int divisibilityTest(int a, int b) {
	while(a > 0) {
		a -= b;
		if ((a < b) && (a != 0)) return 0;
	}
	return 1;
}

int largestPrimeDivisor(int a) {
	if (a < 0) a = -a;
	for (int i = a; i >= 1; i--) {
		int flag = 1;
		if (divisibilityTest(a, i)) {
			for (int j = i-1; j > 1; j--)
				if (divisibilityTest(i, j)) {
					flag = 0;
					break;
				}
			if (flag) return i;
		}
	}
	return 1;
}

int main() {
	int a;
	scanf("%d", &a);
    if (a == 0) {
        printf("n/a");
        return 1;
    }
	printf("%d", largestPrimeDivisor(a));
	return 0;
}

