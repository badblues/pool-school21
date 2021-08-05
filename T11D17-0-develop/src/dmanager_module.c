#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID 100000

void initialize_doors(struct door* doors);
void sort_doors(struct door* doors);
void print_doors(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort_doors(doors);
    doors[5].status = 1;
    print_doors(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % MAX_ID;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
        for (int j = 0; j < DOORS_COUNT - 1; j++)
            if (doors[j].id > doors[j+1].id) {
                struct door tmp = doors[j];
                doors[j] = doors[j+1];
                doors[j+1] = tmp;
            }
    }
}

void print_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++)
        printf("%d, %d\n", doors[i].id, doors[i].status);
}
