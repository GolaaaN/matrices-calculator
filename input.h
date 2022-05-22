#ifndef INPUT_H
#define INPUT_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mat.h"
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



void get_input(char input[]);
int validate_input(char input[], mat mats[6]);
void alert_error(int error);
void skip_spaces(char **p);
void get_command(char *p, char command[]);
int validate_command(char command[]);
int check_comma(char c);
void get_parameter(char *p, char param[]);
void skip_token(char **p);
int validate_parameter(char param[], mat mats[]);
int check_extra(char *p);
int get_values(char input[], int matrices[] ,double values[], int m, int v, mat mats[]);
int get_valuess(char input[], int matrices[], int m, mat mats[]);



void execute_command(int command, char input[], mat mats[6]); /*0*/
void exec_print_mat(char input[], mat mats[]); /*0*/
void exec_read_mat(char input[], mat mats[]); /*X*/
void exec_add_mat(char input[], mat mats[]); /*0*/
void exec_sub_mat(char input[], mat mats[]); /*0*/
void exec_mul_mat(char input[], mat mats[]); /*0*/
void exec_mul_scalar(char input[], mat mats[]);/*X*/
void exec_trans_mat(char input[], mat mats[]); /*0*/
void stop(); /*0*/

enum commands {READ_MAT, PRINT_MAT, ADD_MAT, SUB_MAT, MUL_MAT, MUL_SCALAR, TRANS_MAT, STOP};
enum errors {ERROR = -1 ,UF_MAT_NAME, UF_CMD_NAME, ARG_N_REAL_NUM, EXTRA_TEXT, MISS_ARG, MISS_COMMA, ILLEGAL_COMMA, MULT_CONSEC_COMMA, ARG_N_SCALAR};
/**/

#endif
