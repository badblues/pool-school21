#include "libs.h"
#include "modules.h"
#include "levels.h"
#include "status_events.h"
#include "shared.h"

void menu();
void printMenu0();

int main() {
    menu();
    return 0;
}

void menu() {
    int is_error = 0;
    int choice;
    int flag = 1;
    while (flag) {
        printMenu0();
        choice = getChoice(-1, 1);
        switch (choice) {
            case 0:
                printf(" 0 MODULES\n 1 LEVELS\n 2 EVENTS\n");
                choice = getChoice(0,2);
                if (choice == 0)
                    is_error = modulesControll(); // work with modules
                if (choice == 1)
                    is_error = levelsControll();
                break;
            case 1:
                is_error = showTables();
                break;
            case -1:
                flag = 0;
                break;
        }
        if (is_error) {
            flag = 0;
            printf("error\n");
        }
    }
}

void printMenu0() {
    printf("==============================\n MENU:\n"
    " 0 SELECT TABLE\n 1 SHOW TABLES\n-1 EXIT\n"
    "==============================\n");
}