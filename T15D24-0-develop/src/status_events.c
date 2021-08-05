#include "libs.h"

int print_events(FILE* ptr) {  // OUTPUT
    int is_error = 0;
    events rec;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        fread(&rec, sizeof(events), 1, ptr);
        while(!feof(ptr)) {
            printf("%d %d %d %s %s\n", rec.event_id, rec.module_id, rec.status, rec.date, rec.time);   
            fread(&rec, sizeof(events), 1, ptr);
        }
    }
    return is_error;
}