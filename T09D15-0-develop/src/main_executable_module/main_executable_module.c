#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_libs/data_sort.h"
#include "../data_module/data_process.h"

#include "../yet_another_decision_module/decision.h"


int main() {
    int is_error = 0;
    double *data;
    printf("LOAD DATA...\n");
    int n = getSize();
    if (n == -1)
        is_error = 1;
    if (is_error == 0) {
        is_error = input(data, n);
    }
    if (is_error == 0) {
        printf("RAW DATA:\n\t");
        output(data, n);
        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);
        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, n);
        output(data, n);
        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n))
            printf("YES\n");
        else
            printf("NO\n");
    } else {
        printf("n/a");
    }
    return 0;
}
