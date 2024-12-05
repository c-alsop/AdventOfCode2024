/* 2.h */

#ifndef TASK_2_H
#define TASK_2_H

/* Enum containing what type of order the levels have */
typedef enum {
    UNKNOWN,
    ASCENDING,
    DESCENDING
} ORDER;

/* check_levels()
 * ~~~~~~~~~~~~~~
 * Checks if the levels are safe for part 1. If they are unsafe set the error
 * flag. In order to be safe, the order of the levels must be the same 
 * (ascending or descending) and the difference between levels must be between 1 and 3.
 */
void check_levels(int levels_count, int* levels, int* order, int* error);

/* check_levels()
 * ~~~~~~~~~~~~~~
 * Checks if the levels are safe for part 2. Safety conditions are the same
 * as in part 1, but a single bad level can be tolerated.
 */
void check_levels_2(int levels_count, int* levels, int* order, int* error);

/* remove_level()
 * ~~~~~~~~~~~~~
 * Modifies new_levels so it contains levels but without whichever level is
 * at the index_to_remove 
 */
void remove_level(int** new_levels, int* levels, int levels_count, int index_to_remove);

#endif /* TASK_2_H */
