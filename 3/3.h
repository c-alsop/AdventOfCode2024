/* 3.h */
#ifndef TASK_3_H
#define TASK_3_H

/* extract_num()
 * ~~~~~~~~~~~~~
 * Extracts a 1-3 digit number from the start of contents and stores that
 * in num, returns the number of digits in num (1-3). 
 */
int extract_num(char* contents, int* num);

/* compile_regex()
 * ~~~~~~~~~~~~~~~
 * compiles the regex expression for mul(X,Y) where X and Y are numbers with
 * 1 to 3 digits.
 */
void compile_regex(regex_t* regex);

#endif
