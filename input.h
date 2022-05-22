#ifndef INPUT_H
#define INPUT_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mat.h"

enum commands {READ_MAT, PRINT_MAT, ADD_MAT, SUB_MAT, MUL_MAT, MUL_SCALAR, TRANS_MAT, STOP};
enum errors {ERROR = -1 ,UF_MAT_NAME, UF_CMD_NAME, ARG_N_REAL_NUM, EXTRA_TEXT, MISS_ARG, MISS_COMMA, ILLEGAL_COMMA, MULT_CONSEC_COMMA, ARG_N_SCALAR};


/**
 * gets the input from the user and saves it in the given input array.
 * param - input array.
 * return.
 */
void get_input(char input[]);
/**
 * validates the user's input form and excutes the command.
 * param - input array, matrices.
 * return - 0 in success and 1 in failure.
 */
int validate_input(char input[], mat mats[6]);
/**
 * alerts error by given error number.
 * param - error number.
 * return.
 */
void alert_error(int error);
/**
 * skip spaces in the input.
 * param - adress of pointer to the start of the input.
 * return.
 */
void skip_spaces(char **p);

void get_command(char *p, char command[]);
/**
 * validates the command.
 * param - command.
 * return - 0 if validate and 1 if not.
 */
int validate_command(char command[]);
/**
 * checks if the current char is comma.
 * param - char.
 * return - 0 if it does and 1 if doesn't.
 */
int check_comma(char c);

void get_parameter(char *p, char param[]);
/**
 * skips token.
 * param - address of pointer to the start of the array.
 * return - 0 if it does and 1 if doesn't.
 */
void skip_token(char **p);
/**
 * validate the matrix name.
 * param - matrix, mats.
 * return - returns -1 in ERROR and the matrix index in success.
 */
int validate_parameter(char param[], mat mats[]);

int check_extra(char *p);
int get_values(char input[], int matrices[] ,double values[], int m, int v, mat mats[]);
int get_valuess(char input[], int matrices[], int m, mat mats[]);


/**
 * command handler.
 * param - command num, input, mats.
 * return.
 */
void execute_command(int command, char input[], mat mats[6]); /*0*/
/**
 * command handler.
 * param - command num, input, mats.
 * return.
 */
void exec_print_mat(char input[], mat mats[]); /*0*/
/**
 * exectue command print_mat.
 * param - input, mats.
 * return.
 */
void exec_read_mat(char input[], mat mats[]); /*X*/
/**
 * exectue command red_mat.
 * param - input, mats.
 * return.
 */
void exec_add_mat(char input[], mat mats[]); /*0*/
/**
 * execute command add_mat.
 * param - input, mats.
 * return.
 */
void exec_sub_mat(char input[], mat mats[]); /*0*/
/**
 * execute command mul_mat.
 * param - input, mats.
 * return.
 */
void exec_mul_mat(char input[], mat mats[]); /*0*/
/**
 * execute command mul_scalar.
 * param - input, mats.
 * return.
 */
void exec_mul_scalar(char input[], mat mats[]);/*X*/
/**
 * execute command trans_mat.
 * param - input, mats.
 * return.
 */
void exec_trans_mat(char input[], mat mats[]); /*0*/
/**
 * stops the program.
 * param - input, mats.
 * return.
 */
void stop(); /*0*/
#define COMMAND_MAX 100
#define COMMAND_NUM 8
#define MAT_NUM 6
#define RED   "\x1B[31m"
#define RESET "\x1B[0m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"

/**/

#endif
