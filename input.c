#include "input.h"

char commands_names[COMMAND_NUM][20] = {{"read_mat"},{"print_mat"},{"add_mat"},{"sub_mat"},{"mul_mat"},{"mul_scalar"},{"trans_mat"},{"stop"}};

void get_input(char input[]){
	char *line = input;
	printf("mymat: ");
    if(fgets(input, COMMAND_MAX, stdin) == NULL) {
        return;
    }
	while(line[0] != '\n'){
		if(line[0] == EOF) stop();
		line++;
	}
	printf("Your command: %s", input);
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
	if(input[0] == EOF) stop();
	if(command_num == ERROR){
		alert_error(UF_CMD_NAME);
		return 1;
	}
	execute_command(command_num, input, mats);
	return 0;
}

int validate_input_form(char input[], int min_args){
	int comma_cnt = 0;
	int tokens_cnt = 0;
	char *line = input;
	skip_command(&line);
	/*check comma*/
	if(check_comma(line[0])){
		alert_error(ILLEGAL_COMMA);
		return 1;
	}
	while(line[0] != '\n'){
		skip_command(&line);
		tokens_cnt++;
		if(!check_comma(line[0])){
			skip_spaces(&line);
			if(line[0] == '\n'){
				break;
			}
			alert_error(MISS_COMMA);
			return 1;
		}
		comma_cnt++;
		line++;
		skip_spaces(&line);
		if(check_comma(line[0])){
			alert_error(MULT_CONSEC_COMMA);
			return 1;
		}
	}
	if(comma_cnt >= tokens_cnt && tokens_cnt >= min_args){
		alert_error(EXTRA_TEXT);
		return 1;
	}
	return 0;
}

int get_arguments_m(char input[], int matrices[], int m, mat mats[]){
	const char s[4] = " ,\t\n";
	int mat_index;
	char *token;
	int i=0;
	skip_command(&input);
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

int get_arguments_mv(char input[], int matrices[] ,double values[], int m, int v, mat mats[]){
	const char s[4] = " ,\t\n";
	int mat_index;
	char *token;
	int k = 0;
	int i = 0;
	skip_command(&input);
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
		if(is_num(token)){
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

int get_arguments_mvs(char input[], int matrices[2], double *scalar, mat mats[]){
	const char s[4] = " ,\t\n";
	int mat_index;
	char *token;
	skip_command(&input);
	token = strtok(input, s);
	if(token == NULL){
		alert_error(MISS_ARG);
		return 1;
	}
	if((mat_index = validate_parameter(token, mats)) == ERROR){
		alert_error(UF_MAT_NAME);
		return 1;
	}
	matrices[0] = mat_index;
	/*skip token*/
	skip_token(&input);
	skip_spaces(&input);
	token = strtok(NULL, s);
	if(token == NULL){
		alert_error(MISS_ARG);
		return 1;
	}
	if(is_num(token)){
		alert_error(ARG_N_SCALAR);
		return 1;
	}
	if(token != NULL ){
		*scalar = atof(token);
	} 
	skip_command(&input);
	token = strtok(NULL, s);
	if(token == NULL){
		alert_error(MISS_ARG);
		return 1;
	}
	if((mat_index = validate_parameter(token, mats)) == ERROR){
		alert_error(UF_MAT_NAME);
		return 1;
	}
	matrices[1] = mat_index;
	token = strtok(NULL, " \t\n");
	if(token != NULL){
		alert_error(EXTRA_TEXT);
		return 1;
	}
	return 0;
}
void stop(){
  	printf("mymat: ");
	printf("hope you enjoyed :)\n");
	exit(0);
} 

void skip_command(char **p){
	skip_spaces(p);
	skip_token(p);
	skip_spaces(p);
}

int check_extra(char *p){
	int i;
 	skip_command(&p);
	for(i=0; p[i] == ' ' || p[i] == '\t'; i++){}
	if(p[i] != '\0' && p[i] != '\n'){
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

int is_num(char *str){
	int dotCnt = 0;
	int minCnt = 0;
	int plusCnt = 0;
	if(str == NULL || *str == '\0') return 1;
	while(*str){
		char c = *str;
		switch(c){
			case '.':
				if(dotCnt++ > 1) return 1;
				break;
			case '-':
				if(minCnt++ > 1) return 1;
				break;
			case '+':
				if(plusCnt++ > 1) return 1;
				break;
			default:
				if(c < '0' || c > '9') return 1;
		}
		str++;
	}
	return 0;
}
void alert_error(int error){
	printf("error: ");
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
		case ALLOC_FAILD:
			printf("Allocation faild");
			break;
	}
	printf("\n");
	return;
}



