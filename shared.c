/* shared.c */
#include "shared.h"
#include <stdio.h>
#include <stddef.h>

char* get_contents_of_file(char* file_path) {
    FILE* file = fopen(file_path, "r");
    char* buffer = NULL;
    size_t len = 0;
    getdelim(&buffer, &len, '\0', file);
    fclose(file);
    return buffer;
}

