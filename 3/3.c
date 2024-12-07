#include <stdlib.h>
#include <regex.h>
#include <stdio.h>
#include <sys/types.h>
#include <ctype.h>
#include "my_string.h"
#include "shared.h"
#include "3.h"
#define MATCH_SIZE 1

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Not Enough Args\n");
        exit(1);
    }
    char* contents = get_contents_of_file(argv[1]);
    char* original_contents = contents;

    regex_t regex;
    regmatch_t matches[MATCH_SIZE];
    
    compile_regex(&regex);

    int num1;
    int num2;
    int total = 0;
    int digit_len = 0;

    while (!regexec(&regex, contents, MATCH_SIZE, matches, 0)) {
        //skip over mul(
        contents = contents + matches[0].rm_so + 4;
        
        digit_len = extract_num(contents, &num1);

        //skip over num 1 and ,
        contents = contents + digit_len + 1;
       
        digit_len = extract_num(contents, &num2);
        total += (num1 * num2);

        //skip over num2 and )
        contents = contents + digit_len + 1;
    }

    printf("Total %d\n", total);
    free(original_contents);
    regfree(&regex);
    return 0;
}

int extract_num(char* contents, int* num) {
    int digit_len = 0;
    while (isdigit(contents[digit_len]) && digit_len <= 3) {
        digit_len++;
    }
    char* num_str = splice_str(contents, 0, (digit_len + 1));
    *num = atoi(num_str);
    free(num_str);
    return digit_len;
}

void compile_regex(regex_t* regex) {
    if (regcomp(regex, "mul([0-9]\\{1,3\\},[0-9]\\{1,3\\})", 0)) {
        fprintf(stderr, "Error: Regex\n");
        exit(1);
    }
}
