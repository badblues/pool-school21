#ifndef SRC_ENCODE_H_
#define SRC_ENCODE_H_


int findFiles(char* str);
char* getFullPath(char* dir, char* filename);
int codeCaesars(char* path);
void cleanFile(char* path);
void caesarsCipher(char* path, int shift);

#endif  // SRC_ENCODE_H_
