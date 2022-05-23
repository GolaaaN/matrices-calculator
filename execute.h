#include "mat.h"
#include "input.h"

/**
 * command handler.
 * param - command num, input, mats.
 * return.
 */
void execute_command(int command, char input[], mat mats[6]); 
/**
 * exectue command print_mat.
 * param - input, mats.
 * return.
 */
void exec_print_mat(char input[], mat mats[]); 
/**
 * exectue command red_mat.
 * param - input, mats.
 * return.
 */
void exec_read_mat(char input[], mat mats[]); 
/**
 * execute command add_mat.
 * param - input, mats.
 * return.
 */
void exec_add_mat(char input[], mat mats[]); 
/**
 * execute command mul_mat.
 * param - input, mats.
 * return.
 */
void exec_sub_mat(char input[], mat mats[]); 
/**
 * execute command mul_mat.
 * param - input, mats.
 * return.
 */
void exec_mul_mat(char input[], mat mats[]); 
/**
 * execute command mul_scalar.
 * param - input, mats.
 * return.
 */
void exec_mul_scalar(char input[], mat mats[]);
/**
 * stops the program.
 * param - input, mats.
 * return.
 */
void exec_trans_mat(char input[], mat mats[]); 