#ifndef SRC_MODULES_H_
#define SRC_MODULES_H_

#include "libs.h"

int checkModulesId(FILE* ptr, int id);
int getLastId(FILE* ptr);
int print_modules(FILE* ptr);
void getname(char* name);
modules getModulesRecord(int id);
int addModulesRecord(FILE* ptr, modules rec);
void deleteModulesRecord(FILE* ptr, int id);
int changeModulesRecord(FILE* ptr, int id, modules rec);
int insertModulesRecord(FILE* ptr, int id, modules rec);

#endif  // SRC_MODULES_H_
