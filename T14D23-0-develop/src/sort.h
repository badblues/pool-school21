#ifndef SRC_SORT_H_
#define SRC_SORT_H_
#include "state_sort.h"

int sortFile(FILE* ptr);
int compare(int* rec1, int* rec2);
void swap(FILE* ptr, int* rec1, int* rec2, int id1, int id2);

#endif   // SRC_SORT_H_
