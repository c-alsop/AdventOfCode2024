/* 2.h */

#ifndef TASK_2_H
#define TASK_2_H

/* Enum containing what type of order the levels have */
typedef enum {
    UNKNOWN,
    ASCENDING,
    DESCENDING
} ORDER;

void check_levels(int levels_count, int* levels, int* order, int* error);

void check_levels_2(int levels_count, int* levels, int* order, int* error);

void remove_elem(int** new_levels, int* levels, int levels_count, int index_to_remove);

#endif /* TASK_2_H */
