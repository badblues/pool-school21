#ifndef SRC_LEVELS_H_
#define SRC_LEVELS_H_

int print_levels(FILE* ptr);
levels getLevelsRecord();
int checkLevelsId(FILE* ptr, int id);
int addLevelsRecord(FILE* ptr, levels rec);
int deleteLevelsRecord(FILE* ptr, int id);
int insertLevelsRecord(FILE* ptr, int id, levels new_rec);
int changeLevelsRecord(FILE* ptr, int id, levels rec);

#endif  // SRC_LEVELS_H_
