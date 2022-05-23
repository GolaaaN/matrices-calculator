#include "execute.h"
void execute_command(int command, char input[], mat mats[6]){
	switch(command)
	{
		case READ_MAT:
			if(validate_input_form(input, 2)) return;
			exec_read_mat(input, mats);
		break;
		case PRINT_MAT:
			if(validate_input_form(input, 1)) return;
			exec_print_mat(input, mats);
		break;
		case ADD_MAT:
			if(validate_input_form(input, 3)) return;
			exec_add_mat(input, mats);
		break;
		case SUB_MAT:
			if(validate_input_form(input, 3)) return;
			exec_sub_mat(input, mats);
		break;
		case MUL_MAT:
			if(validate_input_form(input, 3)) return;
			exec_mul_mat(input, mats);
		break;

		case MUL_SCALAR:
			if(validate_input_form(input, 3)) return;
		  	exec_mul_scalar(input, mats);
		break;
		case TRANS_MAT:
			if(validate_input_form(input, 2)) return;
			exec_trans_mat(input, mats);
		break;
		case STOP:
			if(check_extra(input)) return;
			stop();
		break;
	}
}

void exec_print_mat(char input[], mat mats[]){
	int matrices[1];
	if(get_arguments_m(input, matrices, 1, mats)) return;
	print_mat(&mats[matrices[0]]);
}

void exec_read_mat(char input[], mat mats[]){
	double values[16] ={0};
	int matrices[1];
	if(get_arguments_mv(input, matrices, values, 1, 16, mats)) return;
	read_mat(&mats[matrices[0]], values);
}

void exec_add_mat(char input[], mat mats[]){
	int matrices[3];
	if(get_arguments_m(input, matrices, 3, mats)) return;
	add_mat(&mats[matrices[0]], &mats[matrices[1]], &mats[matrices[2]]);
}

void exec_sub_mat(char input[], mat mats[]){
	int matrices[3];
	if(get_arguments_m(input, matrices, 3, mats)) return;
	sub_mat(&mats[matrices[0]], &mats[matrices[1]], &mats[matrices[2]]);
}

void exec_mul_mat(char input[], mat mats[]){
	int matrices[3];
	if(get_arguments_m(input, matrices, 3, mats)) return;
	mul_mat(&mats[matrices[0]], &mats[matrices[1]], &mats[matrices[2]]);
}
void exec_trans_mat(char input[], mat mats[]){
	int matrices[2];
	if(get_arguments_m(input, matrices, 2, mats)) return;
	trans_mat(&mats[matrices[0]], &mats[matrices[1]]);
}

void exec_mul_scalar(char input[], mat mats[]){
	int matrices[2];
	double scalar;
	if(get_arguments_mvs(input, matrices, &scalar, mats)) return;
	mul_scalar(&mats[matrices[0]], scalar, &mats[matrices[1]]);
}
