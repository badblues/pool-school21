#include <stdio.h>

void print_foo(int first_player, int second_player, int racket1, int racket2, int ball2, int ball1);
void Controller(char key, int *LeftRacket_y_Cord, int *RightRacket_y_Cord,
                char* last_key_left, char* last_Key_right);
void evenHandling(int *LeftRacket_y_Cord, int *RightRacket_y_Cord, int *Ball_cord_x,
                  int *Ball_cord_y, int *ScoreL, int *ScoreR, int *BallPhase, char key,
                  char *last_key_left, char *last_key_right);

int main() {
    int first_player_score = 0;  //счёт
    int second_player_score = 0;
    char key;
    int leftBracketY = 12, rightBracketY = 12;  //координаты ракеток
    int ball_X = 40, ball_Y = 12;  //координаты мяча
    char last_key_left;
    char last_key_right;
    int BallPhase = -1;
    print_foo(first_player_score, second_player_score, leftBracketY, rightBracketY, ball_X, ball_Y);
    while (1) {  //главный цикл программы
        if (first_player_score == 21) {
            printf("Ура! Игрок слева победил!\n");
            return 0;
        } else if (second_player_score == 21) {
            printf("Ура! Игрок справа победил!\n");
            return 0;
        }
        while (1) {
            scanf("%c", &key);
            if (key == 'z' || key == 'a' || key == ' ' || key == 'k' || key == 'm')
                break;
        }
        Controller(key, &leftBracketY, &rightBracketY, &last_key_left, &last_key_right);
        evenHandling(&leftBracketY, &rightBracketY, &ball_X, &ball_Y,
                     &first_player_score, &second_player_score, &BallPhase,
                     key, &last_key_left, &last_key_right);
        print_foo(first_player_score, second_player_score,
                  leftBracketY, rightBracketY, ball_X, ball_Y);  //отрисовываем
    }
}

void print_foo(int first_player, int second_player, int racket1, int racket2, int ball2, int ball1) {
    char mat[25][80];
    int string = 25;
    int column = 80;
    int i;
    int j;

    int A, B, C, D;
    char a, b, c, d;

    A = first_player / 10;
    B = first_player % 10;
    C = second_player / 10;
    D = second_player % 10;
    a = (char)A + '0';
    b = (char)B + '0';
    c = (char)C + '0';
    d = (char)D + '0';

    for (i = 0; i < string; i++) {
        for (j = 0; j < column; j++) {
            mat[i][j] = ' ';
            if (i == 0) {
                mat[i][j] = '-';
            } else if (i == string - 1) {
                mat[i][j] = '-';
            } else if (i == ball1 && j == ball2) {
                mat[i][j] = '@';
            } else  if (j == 39 || j == 40) {
                mat[i][j] = '|';
            } else if (i == (racket1 - 1) && j == 0) {
                mat[i][j] = '%';
            } else if (i == racket1 && j == 0) {
                mat[i][j] = '%';
            } else if (i == (racket1 + 1) && j == 0) {
                mat[i][j] = '%';
            } else if (i == (racket2 - 1) && j == column - 1) {
                mat[i][j] = '%';
            } else if (i == racket2 && j == column - 1) {
                mat[i][j] = '%';
            } else if (i == (racket2 + 1) && j == column - 1) {
                mat[i][j] = '%';
            } else if (i == 1 && j == 37) {
                mat[i][j] = a;
            } else if (i == 1 && j == 38) {
                mat[i][j] = b;
            } else if (i == 1 && j == 41) {
                mat[i][j] = c;
            } else if (i == 1 && j == 42) {
                mat[i][j] = d;
            }
        }
    }
    for (i = 0; i < string; i++) {
        for (j = 0; j < column; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

void evenHandling(int *LeftRacket_y_Cord, int *RightRacket_y_Cord, int *Ball_cord_x,
                  int *Ball_cord_y, int *ScoreL, int *ScoreR, int *BallPhase,
                  char key, char *last_key_left, char *last_key_right) {
    if (*Ball_cord_x == 1) {
        if ((*Ball_cord_y == *LeftRacket_y_Cord) ||
            (*Ball_cord_y == *LeftRacket_y_Cord - 1) || (*Ball_cord_y == *LeftRacket_y_Cord + 1)) {
            if (*last_key_left == 'a') {
                *BallPhase = -2;
            } else {
                *BallPhase = 2;
            }
        }
    }
    if (*Ball_cord_x == 0) {
        if ((*Ball_cord_y != *LeftRacket_y_Cord) && (*Ball_cord_y != *LeftRacket_y_Cord - 1)
            && (*Ball_cord_y != *LeftRacket_y_Cord + 1)) {
            (*ScoreR)++;
            *Ball_cord_x = 39;
            *Ball_cord_y = 12;
        }
    }
    if (*Ball_cord_x == 78) {
        if ((*Ball_cord_y == *RightRacket_y_Cord) ||
            (*Ball_cord_y == *RightRacket_y_Cord - 1) || (*Ball_cord_y == *RightRacket_y_Cord + 1)) {
            if (*last_key_left == 'k') {
                *BallPhase = -1;
            } else {
                *BallPhase = 1;
            }
        }
    }
    if (*Ball_cord_x == 79) {
        if ((*Ball_cord_y != *RightRacket_y_Cord) && (*Ball_cord_y != *RightRacket_y_Cord - 1)
            && (*Ball_cord_y != *RightRacket_y_Cord + 1)) {
            (*ScoreL)++;
            *Ball_cord_x = 39;
            *Ball_cord_y = 12;
        }
    }
    if ((*Ball_cord_y == 1) || (*Ball_cord_y == 23)) {
                *BallPhase = - *BallPhase;
    }
    switch (*BallPhase) {
        case -1:
            *Ball_cord_y = *Ball_cord_y - 1;
            *Ball_cord_x = *Ball_cord_x - 1;
            break;
        case -2:
            *Ball_cord_y = *Ball_cord_y - 1;
            *Ball_cord_x = *Ball_cord_x + 1;
            break;
        case 1:
            *Ball_cord_y = *Ball_cord_y + 1;
            *Ball_cord_x = *Ball_cord_x - 1;
            break;
        case 2:
            *Ball_cord_y = *Ball_cord_y + 1;
            *Ball_cord_x = *Ball_cord_x + 1;
            break;
    }
}

void Controller(char key, int *leftRacketY, int *rightRacketY, char* last_key_left, char* last_key_right) {
    if (key == 'a') {
        if (*leftRacketY > 2) {
            *leftRacketY = *leftRacketY - 1;
            *last_key_left = 'a';
        }
    }
    if (key == 'z') {
        if (*leftRacketY < 22) {
            *leftRacketY = *leftRacketY + 1;
            *last_key_left = 'z';
        }
    }
    if (key == 'k') {
        if (*rightRacketY > 2) {
            *rightRacketY = *rightRacketY - 1;
            *last_key_right = 'k';
        }
    }
    if (key == 'm') {
        if (*rightRacketY < 22) {
            *rightRacketY = *rightRacketY + 1;
            *last_key_right = 'm';
        }
    }
}

