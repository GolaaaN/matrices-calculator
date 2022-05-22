#include "input.h"

char commands_names[COMMAND_NUM][20] = {{"read_mat"},{"print_mat"},{"add_mat"},{"sub_mat"},{"mul_mat"},{"mul_scalar"},{"trans_mat"},{"stop"}};

void get_input(char input[]){
	printf(YEL "mymat: "  RESET);
    if(fgets(input, COMMAND_MAX, stdin) == NULL) {
        return;
    }
}


int validate_input(char input[], mat mats[6]){
	int command_num;
	char *line = input;
	char command[COMMAND_MAX];
	/*skip spaces*/
	skip_spaces(&line);
	/*get command*/
	get_command(line, command);
	/*validate command */
	command_num = validate_command(command);
	/*error handler*/
	if(command_num == ERROR){
		alert_error(UF_CMD_NAME);
		return 1;
	}
	skip_token(&line);/*skip command*/
	/*check comma*/
	if(check_comma(line[0])){
		alert_error(ILLEGAL_COMMA);
		return 1;
	}
	while(line[0] != '\n'){
		skip_spaces(&line);
		skip_token(&line);
		skip_spaces(&line);
		if(!check_comma(line[0])){
			skip_spaces(&line);
			if(line[0] == '\n'){
				break;
			}
			alert_error(MISS_COMMA);
			return 1;
		}
		line++;
		skip_spaces(&line);
		if(check_comma(line[0])){
			alert_error(MULT_CONSEC_COMMA);
			return 1;
		}

	}
	execute_command(command_num, input, mats);
	return 0;
}

void execute_command(int command, char input[], mat mats[6]){
	switch(command)
	{
		case READ_MAT:
			exec_read_mat(input, mats);
		break;

		case PRINT_MAT:
			exec_print_mat(input, mats);
		break;

		case ADD_MAT:
			exec_add_mat(input, mats);
		break;

		case SUB_MAT:
			exec_sub_mat(input, mats);
		break;

		case MUL_MAT:
			exec_mul_mat(input, mats);
		break;

		case MUL_SCALAR:
		  	exec_mul_scalar(input, mats);
		break;

		case TRANS_MAT:
			exec_trans_mat(input, mats);
		break;

		case STOP:
			stop();
		break;
	}
}

void stop(){
  	printf(YEL "mymat: "  RESET);
	printf("hope you enjoyed :)\n");
	exit(0);
} 

void exec_print_mat(char input[], mat mats[]){
	int matrices[1];
	if(get_valuess(input, matrices, 1, mats)) return;
	print_mat(&mats[matrices[0]]);
}

int check_extra(char *p){
	int i;
	for(i=0; p[i] == ' ' || p[i] == '\t'; i++){}
	if(p[i] != '\0' && p[i] != '\n'){
		putchar(p[i]);
		alert_error(EXTRA_TEXT);
		return 1;
	}
	return 0;
}

int validate_parameter(char param[], mat mats[]){
	int i;
	for(i = 0; i < MAT_NUM; i++){
		if(strcmp(mats[i].name, param) == 0){
			return i;
		}
	}
	return ERROR;
}

int check_comma(char c){
	if(c == ','){
		return 1;
	}
	return 0;
}
void get_parameter(char *p, char param[]){
	int n,j;
	n = j = 0;
	while((p)[n] != EOF && (p)[n] != '\n' && (p)[n] != '\t' && (p)[n] != ' ' && (p)[n] != ',' && n < 7){
		param[j] = p[n];
		j++;
		n++;
	}
	param[j] = '\0';
}

void skip_token(char **p){
	int n = 0;
	while((*p)[n] != EOF && (*p)[n] != '\n' && (*p)[n] != '\t' && (*p)[n] != ' ' && (*p)[n] != ','){
		n++;
	}
	*p += n;
}


int validate_command(char command[]){
	int i;
	for(i = 0; i < COMMAND_NUM; i++){
		if(strcmp(commands_names[i], command) == 0) return i;
	}
	return -1;
}

void get_command(char *p, char command[]){
	int j,i;
	for(i = j = 0; p[i]!= EOF && p[i] != '\n' && p[i] != ' ' && p[i] != '\t'; i++){
		command[j] = p[i];
		j++;
	}
	command[j] = '\0';
}

void skip_spaces(char **p){
	int n;
	for(n = 0; ((*p)[n] == ' ' || (*p)[n] == '\t'); n++){}
	*p += n;
}

void exec_read_mat(char input[], mat mats[]){
	double values[16];
	int matrices[1];
	if(get_values(input, matrices, values, 1, 16, mats)) return;
	printf("%f",values[0]);
	read_mat(&mats[matrices[0]], values);
}

int get_values(char input[], int matrices[] ,double values[], int m, int v, mat mats[]){
	const char s[4] = " ,\t\n";
	int mat_index;
	char *token;
	int k = 0;
	int i = 0;
	skip_spaces(&input);
	skip_token(&input);
	skip_spaces(&input);
	token = strtok(input, s);
	
	if(token == NULL){
			alert_error(MISS_ARG);
			return 1;
	}
	if((mat_index = validate_parameter(token, mats)) == ERROR){
			alert_error(UF_MAT_NAME);
			return 1;
	}
	matrices[i] = mat_index;
	for(i = 1; i < m; i++){
		token = strtok(NULL, s);
		if(token == NULL){
			alert_error(MISS_ARG);
			return 1;
		}
		if((mat_index = validate_parameter(token, mats)) == ERROR){
			alert_error(UF_MAT_NAME);
			return 1;
		}
		matrices[i] = mat_index; 
	}
	token = strtok(NULL, s);
	if(token == NULL){
		alert_error(MISS_ARG);
		return 1;
	}
	while(token != NULL){
		if(token != NULL && atof(token) == 0){
			alert_error(ARG_N_REAL_NUM);
			return 1;
		}
		if(token != NULL && k < v){
			values[k] = atof(token);
		} 
		k++;
		token = strtok(NULL, s);
	}
	return 0;
}
int get_valuess(char input[], int matrices[], int m, mat mats[]){
	const char s[4] = " ,\t\n";
	int mat_index;
	char *token;
	int i=0;
	skip_spaces(&input);
	skip_token(&input);
	skip_spaces(&input);

	token = strtok(input, s);
	if(token == NULL){
			alert_error(MISS_ARG);
			return 1;
	}
	if((mat_index = validate_parameter(token, mats)) == ERROR){
			alert_error(UF_MAT_NAME);
			return 1;
	}
	matrices[i] = mat_index;
	for(i = 1; i < m; i++){
		token = strtok(NULL, s);
		if(token == NULL){
			alert_error(MISS_ARG);
			return 1;
		}
		if((mat_index = validate_parameter(token, mats)) == ERROR){
			alert_error(UF_MAT_NAME);
			return 1;
		}
		matrices[i] = mat_index; 
	}	
	token = strtok(NULL, " \t\n");
	if(token != NULL){
		alert_error(EXTRA_TEXT);
		return 1;
	}
	return 0;
}



void exec_add_mat(char input[], mat mats[]){
	int matrices[3];
	if(get_valuess(input, matrices, 3, mats)) return;
	add_mat(&mats[matrices[0]], &mats[matrices[1]], &mats[matrices[2]]);
}


void exec_sub_mat(char input[], mat mats[]){
	int matrices[3];
	if(get_valuess(input, matrices, 3, mats)) return;
	sub_mat(&mats[matrices[0]], &mats[matrices[1]], &mats[matrices[2]]);
}


void exec_mul_mat(char input[], mat mats[]){
	int matrices[3];
	if(get_valuess(input, matrices, 3, mats)) return;
	mul_mat(&mats[matrices[0]], &mats[matrices[1]], &mats[matrices[2]]);

}
void exec_trans_mat(char input[], mat mats[]){
	int matrices[2];
	if(get_valuess(input, matrices, 2, mats)) return;
	trans_mat(&mats[matrices[0]], &mats[matrices[1]]);
}
void exec_mul_scalar(char input[], mat mats[]){}


void alert_error(int error){
	printf(RED "error: " RESET);
	switch(error)
	{
		case UF_MAT_NAME:
			printf("Undefined matrix name");
			break;

		case UF_CMD_NAME:
			printf("Undefined command name");
			break;

		case ARG_N_REAL_NUM:
			printf("Argument is not a real number");
			break;

		case EXTRA_TEXT:
			printf("Extraneous text after end of command ");
			break;

		case MISS_ARG:
			printf("Missing argument");
			break;

		case MISS_COMMA:
		  	printf("Missing comma");
			break;

		case ILLEGAL_COMMA:
			printf("Illegal comma");
			break;
		case MULT_CONSEC_COMMA:
			printf("Multiple consecutive commas");
			break;
		case ARG_N_SCALAR:
			printf("Argument is not a scalar");
			break;	
	}
	printf("\n");
	return;
}





