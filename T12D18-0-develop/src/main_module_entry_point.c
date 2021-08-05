#include <stdio.h>

#include "print_module.h"
#include "documentation_module.h"

int main() {
    #ifdef Quest_1
    print_log(print_char, Module_load_success_message);
    #endif

    #ifdef Quest_2
    short availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    print_docs(availability_mask, Documents_count, Documents);
    #endif

    return 0;
}
