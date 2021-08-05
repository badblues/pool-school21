#include <stdio.h>
#include <stdlib.h>

void allocateMemory(char*** matrix, int height, int width);
void fill(char** matrix, int height, int width);
void addFigure(char** matrix);
void init(char*** matrix, int height, int width, int* gen);
void print(char** matrix, int height, int width, int gen);
int check(char** matrix, int y, int x);
void updateMatrix(char** matrix1, char*** matrix2, int height, int width, int *flag);
void nextTurn();
void swapMatrices(char*** m1, char*** m2);
void compare(char** matrix1, char** matrix2, int height, int width, int *flag);


int main() {
    int gen;
    int end_flag = 0;
    int N = 25, M = 80;
    char** matrix1;
    char** matrix2;
    init(&matrix1, N, M, &gen);
    allocateMemory(&matrix2, N, M);
    while (1) {
        gen++;
        nextTurn();
        updateMatrix(matrix1, &matrix2, N, M, &end_flag);
        compare(matrix1, matrix2, N, M, &end_flag);
        print(matrix2, N, M, gen);
        swapMatrices(&matrix2, &matrix1);
        if (end_flag == 1) {
            printf("End of life  (◞‸◟；)\n");
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    return 0;
}

void allocateMemory(char*** matrix, int height, int width) {
    *matrix = (char**)malloc(sizeof(char*) * height);
    char* tmp = (char*)malloc(sizeof(char) * height * width);
    for (int i = 0; i < height; i++)
        (*matrix)[i] = tmp + i * width;
}

void fill(char** matrix, int height, int width) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            matrix[i][j] = ' ';
}

void addFigure(char** matrix) {
    int i = 6, j = 20;
    char c;
    scanf("%c", &c);
    while (c != '/') {
        switch (c) {
            case 'X':
                matrix[i][j++] = 'X';
                break;
            case ' ':
                j++;
                break;
            case '\n':
                j = 20;
                i++;
                break;
        }
        scanf("%c", &c);
    }
}

void init(char*** matrix, int height, int width, int* gen) {
    *gen = 0;
    allocateMemory(matrix, height, width);
    fill(*matrix, height, width);
    addFigure(*matrix);   // adding first figure from file or by console
    freopen("/dev/tty", "r", stdin);
    print(*matrix, height, width, *gen);
}

void print(char** matrix, int height, int width, int gen) {
    printf("\033c");
    printf("                              "
           "|Generation: %d|\n", gen);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            printf("%c", matrix[i][j]);
        printf("\n");
    }
}

int check(char** matrix, int y, int x) {
    int counter = 0;
    for (int i = y - 1; i <= y + 1; i++)
        for (int j = x - 1; j <= x + 1; j++) {
            int posi = i, posj = j;
            if (posi == -1) posi = 24;
            if (posi == 25) posi = 0;
            if (posj == -1) posj = 79;
            if (posj == 80) posj = 0;
            if ((matrix[posi][posj] == 'X') && ((posi != y) || (posj != x))) {
                counter++;
            }
        }
    return counter;
}

void updateMatrix(char** matrix1, char*** matrix2, int height, int width, int *flag) {
    int counter = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            (*matrix2)[i][j] = ' ';
            int s = check(matrix1, i, j);
            counter += s;
            if (s > 0)
                if (((matrix1[i][j] == 'X') && (s == 2 || s == 3)) ||
                    ((matrix1[i][j] == ' ') && (s == 3)))
                        (*matrix2)[i][j] = 'X';
        }
    }
    if (counter == 0)
        *flag = 0;
}

void compare(char** matrix1, char** matrix2, int height, int width, int *flag) {
    *flag = 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (matrix2[i][j] != matrix1[i][j]) {
                *flag = 0;
                return;
            }
        }
    }
}

void swapMatrices(char*** m1, char*** m2) {
    char** tmp = *m1;
    *m1 = *m2;
    *m2 = tmp;
}

void nextTurn() {
    char key;
    while (1) {
        if (scanf("%c", &key) == -1) {
            printf("GOTCHA");
            freopen("/dev/tty", "r", stdin);
        }
        if (key == ' ')
            break;
    }
}
