/* 1.c */
#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"
#include "shared.h"
#include "1.h"

int compare(const void* arg1, const void* arg2) {
    return *(int*)arg1 > *(int*)arg2;
}

void split_left_right(int** left, int** right, int* arr_to_split, int nums_size) {
    size_t right_index = 0;
    size_t left_index = 0;

    for (int i = 0; i < nums_size; i++) {
        if (i%2) {
            (*right)[right_index++] = arr_to_split[i];
        } else {
            (*left)[left_index++] = arr_to_split[i];
        }
    }
}

int calc_dist(int* left, int* right, int size) {
    int dist = 0;
    for (int i = 0; i < size; i++) {
        dist += abs(left[i] - right[i]);
    }
    return dist;
}

int similarity_score(int* left, int* right, int size) {
    int total_score = 0;
    int current_num_score = 0;
    int left_index = 0;
    int right_index = 0;

    while (left_index < size) {
        if (left_index && left[left_index] == left[left_index - 1]) {
            total_score += current_num_score;
            left_index++;
        } else if (left[left_index] == right[right_index]) {
            total_score += left[left_index];
            current_num_score += left[left_index];
            right_index++;
        } else if (right[right_index] < left[left_index]) {
            right_index++;
            current_num_score = 0;
        } else {
            left_index++;
            current_num_score = 0;
        }
    }
    return total_score;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Not Enough Args\n");
        exit(1);
    }

    char* buffer = get_contents_of_file(argv[1]);

    int* nums = malloc(sizeof(int));
    int nums_size = split_string_to_int(&nums, buffer, " \n\r");

    int* left = malloc(sizeof(int) * (nums_size/2));
    int* right = malloc(sizeof(int) * (nums_size/2));

    split_left_right(&left, &right, nums, nums_size);

    qsort(right, nums_size/2, sizeof(int), compare);
    qsort(left, nums_size/2, sizeof(int), compare);

    printf("Part 1 Answer: %d\n", calc_dist(left, right, nums_size/2));
    printf("Part 2 Answer: %d\n", similarity_score(left, right, nums_size/2));

    free(left);
    free(right);
    free(nums);
    free(buffer);
    return 0;
}
