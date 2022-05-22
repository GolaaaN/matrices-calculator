#include "mat.h"
#include "input.h"



void processor(mat mats[6]){
	while(1){
    char input[COMMAND_MAX];
    get_input(input);
	validate_input(input, mats);}
}

int main()
{
    mat mats[MAT_NUM];    
    init_matrix(mats);
    processor(mats);
    return 0;
}
