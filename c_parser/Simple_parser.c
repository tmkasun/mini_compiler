//
// Created by tmkasun
//

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/* Define bit masks to be used in the rest of the program */
#define WORD_TOKEN  0
#define NUMBER_TOKEN  1
#define INIT  -1


int main(int argc, char *argv[]) {

    FILE *fp_input = NULL; /* Define FILE pointer to hold the open file */

    fp_input = fopen(
            "/Users/tmkasun/Documents/uni/Level4_Semester2/CM 4220 - Theory of Compilers/labs/c_parser/sample_input.txt",
            "r"); /* Open sample input file in Read Only mode */

    if (fp_input ==
        NULL) { /* Check whether the variable is not null to make sure that file descriptor has being loaded in to memory */
        perror("No input file!\n");
        return 1;
    }
    printf("Input file opened sucsussfully!\n");


    char token[255]; /* Define character array to hold the currently identified token */
    int token_index = 0; /* Current index position of the above @token char array */
    int token_type = INIT; /* Guessed token type of the string currently being processed */
    int line_number = 0, column_number = 0; /* integer variable to keep current line number and there column number, to be used to pin point an error if occurred  */

    int current_character; /* To hold the current character read from input file*/
    while (TRUE) {
        current_character = fgetc(fp_input); /* Read one character from input file */
        ++column_number; /* Increase colum counter by 1 */
        /*
        ASCII table which have being used to tokenize [a-z] characters and [0-9] numeric characters from input
        ASCII => Dec
        a => 97
        z => 122
       ' '=> 32
        0 => 48
        9 => 57
        \n => 10
         */

        /* Check whether the current input character lying between ASCII 'a' and 'z'
         * and whether the token type has identified as WORD_TOKEN or it is in initial(INIT) state */
        if (97 <= current_character && current_character <= 122 && (token_type == WORD_TOKEN || token_type == INIT)) {
            token[token_index++] = (char) current_character; /* Put the character in to the next position of the currently identified token and do post increment the pointer */
            token_type = WORD_TOKEN; /* Set the type of the currently processing token as WORD_TOKEN */
        }

            /* Check whether the current input character lying between ASCII '0' and '9'
             * and whether the token type has identified as WORD_TOKEN or it is in initial(INIT) state */
        else if (48 <= current_character && current_character <= 57 &&
                 (token_type == NUMBER_TOKEN || token_type == INIT)) {
            token[token_index++] = (char) current_character;
            token_type = NUMBER_TOKEN;
        }

            /* Condition to check whether the current input character is an empty space or a newline character */
        else if (current_character == 32 || current_character == 10) {
            current_character == 10 ? ++line_number, column_number = 0
                                    : TRUE; /* If current input is newline character(\n), increase line_number and reset column_number  */
            if (token_index != 0) { /* If token has identified */
                token_type == WORD_TOKEN ? printf("Found a WORD token %s\n", token) : printf(
                        "Found a NUMBER token %s\n", token); /* Display the token separated by space */
                token_index = 0; /* Reset variable */
                token_type = -1; /* Reset variable */
                memset(token, 0,
                       sizeof(token)); /* Reset the memory area used by token character array buffer (fill buffer with NULL elements) */
            }
            continue; /* Continue scanning the file without going further down the while loop body */

        }
        else if (current_character == EOF) { /* If reached to the end of file character */
            if (token_index != 0) /* If a token has being identified */
                token_type == WORD_TOKEN ? printf("Found a WORD token %s\n", token) : printf(
                        "Found a NUMBER token %s\n",
                        token); /* Display the token with its relevant type (WORD_TOKEN or NUMBER_TOKEN) */
            break; /* Break out of the loop, which also stop the file read */
        }
        else { /* If none of the above conditions has been satisfied, then it is an unknown character/state */
            printf("ERROR in line %d column %d : Unknown character `%c` \n", line_number + 1,
                   column_number,
                   current_character); /* Display an error message with origin of the error, giving Line number and Column number of that line(Number of characters from the beginning of that line)*/
            break; /* Break out of the loop, if an error occurred */
        }
    }

    fclose(fp_input); /* Close opened file */
    return 0;
}