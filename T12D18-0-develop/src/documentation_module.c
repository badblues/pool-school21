#include "documentation_module.h"
#include <stdarg.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

short check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    int is_error = 0;
    int sum = 16384;
    va_list ptr;
    va_start(ptr, document_count);
    int step = 1;
    if (document_count > 13)
        is_error = 1;
    if (is_error == 0)
        while (document_count--) {
        char* str = va_arg(ptr, char*);
            sum += validate(str) * step;
            step *= 2;
        }
    va_end(ptr);
    return sum;
}
