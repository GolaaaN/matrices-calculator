#include "mat.h"


void init_matrix(mat *ptr){
    strcpy(ptr[0].name, "MAT_A");
    strcpy(ptr[1].name, "MAT_B");
    strcpy(ptr[2].name, "MAT_C");
    strcpy(ptr[3].name, "MAT_D");
    strcpy(ptr[4].name, "MAT_E");
    strcpy(ptr[5].name, "MAT_F");
	reset(ptr[0].matrix);
	reset(ptr[1].matrix);
	reset(ptr[2].matrix);
	reset(ptr[3].matrix);
	reset(ptr[4].matrix);
	reset(ptr[5].matrix);
}

void print_mat(mat *a){
    int i,k;
    for(i = 0; i < SIZE; i++){
        for(k = 0; k < SIZE; k++){
           printf("%9.2f", a->matrix[i][k]);
        }
        printf("\n");
    }
}

void reset(double matrix[4][4]){
    int i,k;
    for(i = 0; i < SIZE; i++){
        for(k = 0; k < SIZE; k++){
            matrix[i][k] = 0;
        }
    }
}

void add_mat(mat *A, mat *B, mat *C){
	int i,k;
	for(i = 0; i < SIZE; i++){
		for(k = 0; k < SIZE; k++){
			C->matrix[i][k] = A->matrix[i][k] + B->matrix[i][k];
		}
	}
	
}
void sub_mat(mat *A, mat *B, mat *C){
	int i,k;
	for(i = 0; i < SIZE; i++){
		for(k = 0; k < SIZE; k++){
			C->matrix[i][k] = A->matrix[i][k] - B->matrix[i][k];
		}
	}
}
void mul_mat(mat *A, mat *B, mat *C){
	int i,k;
	for(i = 0; i < SIZE; i++){
		for(k = 0; k < SIZE; k++){
			C->matrix[i][k] = A->matrix[i][k] * B->matrix[i][k];
		}
	}
}

void trans_mat(mat *A, mat *B){
	

}

void read_mat(mat *A, double values[]){
	int i,k;
	for(i = 0; i < SIZE; i++){
		for(k = 0; k < SIZE; k++){
			A->matrix[i][k] = values[i*k];
			
		}
	}
	print_mat(A);

}


