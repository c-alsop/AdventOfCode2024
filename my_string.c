/* my_string.c */
#include <string.h>
#include <stdlib.h>
#include "my_string.h"
#include <stdio.h>

int split_string(char*** split_string, char* string_to_split, char* delim) {
    int index = 0;
    char* token = strtok(string_to_split, delim);
    
    if (token == NULL) {
        *split_string = NULL;
        return 0;
    }

    *split_string = realloc(*split_string, sizeof(char*) * (index + 1));
    if (*split_string == NULL) {
        fprintf(stderr, "Realloc failed\n");
    }

    (*split_string)[index] = strdup(token);

    while ((token = strtok(NULL, delim)) != NULL) {
        index++;
        *split_string = realloc(*split_string, sizeof(char*) * (index + 1));
        (*split_string)[index] = strdup(token);
    }
    return ++index;
}

int split_string_to_int(int** split_int, char* string_to_split, char* delim) {
    int index = 0;
    char* token = strtok(string_to_split, delim);

    *split_int = realloc(*split_int, sizeof(int) * (index + 1));
    char* str_token = strdup(token);
    (*split_int)[index] = atoi(str_token);
    free(str_token);

    while ((token = strtok(NULL, delim)) != NULL) {
        index++;
        *split_int = realloc(*split_int, sizeof(int) * (index + 1));
        str_token = strdup(token);
        (*split_int)[index] = atoi(str_token);
        free(str_token);
    }
    return ++index;
}

char* splice_str(char* str_to_splice, int start_index, int end_index) {
    size_t size = end_index - start_index;
    char* spliced_str = malloc(sizeof(char) * (size + 1));
    strncpy(spliced_str, (str_to_splice + start_index), size);
    spliced_str[size] = '\0';
    return spliced_str;
}
