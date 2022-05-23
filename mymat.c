#include "mat.h"
#include "input.h"

void my_mat_loop(mat mats[6]);

int main()
{
    mat mats[6];    
    init_matrix(mats);
    my_mat_loop(mats);
    return 0;
}


void my_mat_loop(mat mats[6]){
	while(1){
    	char input[COMMAND_MAX];
    	get_input(input);
		validate_input(input, mats);
	}
}