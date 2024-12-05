/* 2.c */
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "my_string.h"
#include "2.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Not Enough Args");
        exit(1);
    }

    size_t len = 0;
    char* line = NULL;
    int* levels = malloc(sizeof(int));
    int levels_count;
    int order;
    int error;
    int report_count = 0;

    FILE* file = fopen(argv[1], "r");

    while (getline(&line, &len, file) != -1) {
        levels_count = split_string_to_int(&levels, line, " ");
        order = UNKNOWN;
        error = 0;

        //part 1
        //check_levels(levels_count, levels, &order, &error);

        //part 2
        check_levels_2(levels_count, levels, &order, &error);

        if (!error) {
            report_count++;
        }
    }

    printf("Safe Reports: %d\n", report_count);

    free(line);
    free(levels);
    fclose(file);
    return 0;
}

void check_levels(int levels_count, int* levels, int* order, int* error) {
    for (int i = 1; i < levels_count; i++) {
        if (*order != DESCENDING && levels[i] > levels[i - 1]) {
            *order = ASCENDING;
        } else if (*order != ASCENDING && levels[i] < levels[i-1]) {
            *order = DESCENDING;
        } else {
            *error = 1;
            break;
        }
        if (abs(levels[i] - levels[i-1]) > 3 ||
                abs(levels[i] - levels[i-1]) < 1) {
            *error = 1;
            break;
        }
    }
}

void check_levels_2(int levels_count, int* levels, int* order, int* error) {
    int* new_levels = malloc(sizeof(int) * (levels_count - 1));
    for (int skip = 0; skip < levels_count; skip++) {
        *error = 0;
        *order = UNKNOWN;
        remove_level(&new_levels, levels, levels_count, skip);
        check_levels((levels_count - 1), new_levels, order, error);
        if (!(*error)) {
            free(new_levels);
            return;
        }
    }
    free(new_levels);
}

void remove_level(int** new_levels, int* levels, int levels_count, int index_to_remove) {
    for (int i = 0; i < (levels_count - 1); i++) {
        (*new_levels)[i] = levels[i < index_to_remove ? i : i + 1];
    }
}
