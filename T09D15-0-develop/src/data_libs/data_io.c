#include <stdio.h>
int getSize() {
    int n;
    if (scanf("%d", &n) != 1)
        return -1;
    return n;
}

int input(double* data, int n) {
    int is_error = 0;
    for (int i = 0; i < n; i++)
        if (scanf("%lf", &(data[i])) != 1) {
            is_error = 1;
            break;
        }
    char c;
    if ((scanf("%c", &c) != 0) && (c != '\n'))
        is_error = 1;
    return is_error;
}

void output(double* data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != n - 1)
            printf(" ");
    }
}
