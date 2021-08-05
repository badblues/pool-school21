#include <stdio.h>
#include <math.h>

double witchOfAgnesi(double x) {
	double y = 1/(1 + x*x);
	return y;
}

double lemniscateOfBernoulli(double x) {
	if (sqrt(1 + 4 * x * x) - x * x - 1 < 0 ) return 1;
	double y = sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
	return y;
}

double squareHyperbola(double x) {
	double y = 1/(x * x);
	return y;
}

int main() {
    for (int i = 0; i <= 41; i ++) {
        double tmp = -M_PI + (2 * M_PI / 41) * i;
        printf("%.7f | %.7f | ", tmp, witchOfAgnesi(tmp));
        if (lemniscateOfBernoulli(tmp) == 1)
            printf("- | ");
        else
            printf("%.7f | ", lemniscateOfBernoulli(tmp));
        printf("%.7f\n", squareHyperbola(tmp));
	}
	return 0;
}
