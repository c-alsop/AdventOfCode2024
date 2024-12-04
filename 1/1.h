/* 1.h */

#ifndef 1_H
#define 1_H

/* compare()
 * ~~~~~~~~~
 * Returns 1 if arg1 is greater than arg2, 0 otherwise */
int compare(const void* arg1, const void* arg2);

/* split_left_right()
 * ~~~~~~~~~~~~~~~~~~
 * Takes in an arr_to_split, and splits it into left and right arrays. */
void split_left_right(int** left, int** right, int* arr_to_split, int nums_size); 

/* calc_dist()
 * ~~~~~~~~~~~
 * Calculates the total distance between the left and right lists
 */
int calc_dist(int* left, int* right, int size);

/* similarity_score()
 * ~~~~~~~~~~~~~~~~~~
 * Calculates the similarity score between the left and right lists
 */
int similarity_score(int* left, int* right, int size);

#endif /* 1_H */
