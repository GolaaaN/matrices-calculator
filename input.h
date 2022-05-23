#ifndef INPUT_H
#define INPUT_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mat.h"
#include "execute.h"
#define COMMAND_MAX 1000
#define COMMAND_NUM 8

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
/**
 * gets the command.
 * param - input, command array to store the command.
 * return.
 */
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
/**
 * skips token.
 * param - address of pointer to the start of the array.
 * return - 0 if it does and 1 if doesn't.
 */
void skip_token(char **p);
/**
 * skips command or token.
 * param - address of pointer.
 * return.
 */
void skip_command(char **p);
/**
 * validates the matrix name.
 * param - matrix, mats.
 * return - returns -1 in ERROR and the matrix index in success.
 */
int validate_parameter(char param[], mat mats[]);
/**
 * checks extra text for 0 paramaters commands.
 * param - char pointer.
 * return - returns 1 in false and 0 in true.
 */
int check_extra(char *p);
/**
 * get all the arguments for matrices & values commands.
 * param - input, mats arr, values arr, num of mats, num of max values, the matrices.
 * return - return - returns 1 in false and 0 in true.
 */
int get_arguments_mv(char input[], int matrices[] ,double values[], int m, int v, mat mats[]);
/**
 * get all the arguments for matrices commands.
 * param - input, mats arr, num of mats, the matrices.
 * return - return - returns 1 in false and 0 in true.
 */
int get_arguments_m(char input[], int matrices[], int m, mat mats[]);
/**
 * get all the arguments for matrices & values commands.
 * param - input, mats arr, double scalar, the matrices.
 * return - return - returns 1 in false and 0 in true.
 */
int get_arguments_mvs(char input[], int matrices[2], double *scalar, mat mats[]);
/**
 * validates that string text is double.
 * param - string.
 * return - return - returns 1 in false and 0 in true.
 */
int is_num(char *str);
/**
 * validates the input form.
 * param - input, min arguments.
 * return - return - returns 1 in false and 0 in true.
 */
int validate_input_form(char input[], int min_args);
/**
 * stops the program.
 * param.
 * return.
 */
void stop(); 

enum commands {READ_MAT, PRINT_MAT, ADD_MAT, SUB_MAT, MUL_MAT, MUL_SCALAR, TRANS_MAT, STOP};
enum errors {ERROR = -1 ,UF_MAT_NAME, UF_CMD_NAME, ARG_N_REAL_NUM, EXTRA_TEXT, MISS_ARG, MISS_COMMA, ILLEGAL_COMMA, MULT_CONSEC_COMMA, ARG_N_SCALAR, ALLOC_FAILD};


#endif
