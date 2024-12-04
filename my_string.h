/* my_string.h */

#ifndef MY_STRING_H
#define MY_STRING_H

/* split_string()
 * ~~~~~~~~~~~~~~
 * Takes in a string to split, a delimiter to split on and a pointer to a
 * char** to store the split string in. Returns the size of the split_string.
 */
int split_string(char*** split_string, char* string_to_split, char* delim);

/* split_string_to_int()
 * ~~~~~~~~~~~~~~~~~~~~~
 * Takes in a string to split, a delimiter to split on and a pointer to a
 * int* to store the converted split string. Returns the size of the converted
 * split string (split_int). */
int split_string_to_int(int** split_int, char* string_to_split, char* delim);

/* splice_str()
 * ~~~~~~~~~~~~
 * Takes in a string to splice and splices it from the start index, up to
 * but not including the end_index. Returns spliced string.
 */
char* splice_str(char* str_to_splice, int start_index, int end_index);

#endif /* MY_STRING_H */
