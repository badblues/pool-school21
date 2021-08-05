#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_
#include <stdio.h>

#include "log_levels.h"

char* createMes(char* path, int mode);
FILE* log_init(char* path);
void logcat(FILE* ptr, char* message, enum log_level level);
void log_close(FILE* ptr);

#endif  // SRC_LOGGER_H_
