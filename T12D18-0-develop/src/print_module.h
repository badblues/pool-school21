#ifndef SRC_PRINT_MODULE_H_
#define SRC_PRINT_MODULE_H_

#define Module_load_success_message "Output stream module load: success\n"
#define Log_prefix "[LOG]"

/*
    input:  printchar-callback, log message 
    output: void
    result: "Log_prefix HH:MM:SS message"
*/
void print_log(char (*print)(char), char* message);

char print_char(char ch);

void print_docs(short mask, int documents_count, ...);

#endif  // SRC_PRINT_MODULE_H_
