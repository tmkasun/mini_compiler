//
// Created by tmkasun
//

#include <stdio.h>
#include <string.h>
#include <tcl.h>

#define TRUE 1
#define FALSE 0


int main(int argc, char *argv[]) {

    FILE *fp_input = NULL;

    fp_input = fopen(
            "/Users/tmkasun/Documents/uni/Level4_Semester2/CM 4220 - Theory of Compilers/labs/c_parser/sample_input.txt",
            "r");

    if (fp_input == NULL) {
        perror("No input file!\n");
        return 1;
    }
    printf("Input file opened sucsussfully!\n");


    CONST int WORD_TOKEN = 0;
    CONST int NUMBER_TOKEN = 1;
    CONST int INIT = -1;

    char token[255];
    int token_index = 0;
    int token_type = INIT;
    int line_number = 0, column_number = 0;

    int current_character;
    while (TRUE) {
        current_character = fgetc(fp_input);
        ++column_number;
        /*
        ASCII => Dec
        a => 97
        z => 122
       ' '=> 32
        0 => 48
        9 => 57
        \n => 10
         */
        if (97 <= current_character && current_character <= 122 && (token_type == WORD_TOKEN || token_type == INIT)) {
            token[token_index++] = (char) current_character;
            token_type = WORD_TOKEN;
        }
        else if (48 <= current_character && current_character <= 57 &&
                 (token_type == NUMBER_TOKEN || token_type == INIT)) {
            token[token_index++] = (char) current_character;
            token_type = NUMBER_TOKEN;
        }
        else if (current_character == 32 || current_character == 10) {
            current_character == 10 ? ++line_number, column_number = 0 : TRUE;
            if (token_index != 0) {
                token_type == WORD_TOKEN ? printf("Found a WORD token %s\n", token) : printf(
                        "Found a NUMBER token %s\n", token);
                token_index = 0;
                token_type = -1;
                memset(token, 0, sizeof(token));
            }
            continue;

        }
        else if (current_character == EOF) {
            if (token_index != 0)
                token_type == WORD_TOKEN ? printf("Found a WORD token %s\n", token) : printf(
                        "Found a NUMBER token %s\n", token);
            break;
        }
        else {
            printf("ERROR in line %d column %d : Unknown character `%c` \n", line_number + 1,
                   column_number, current_character);
            break;
        }
    }

    fclose(fp_input);
    return 0;
}


void reset_parameters() {

}