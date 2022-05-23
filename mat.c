#include "mat.h"


void init_matrix(mat *ptr){
	int i;
	for(i = 0; i < MAT_NUM; i++){
		reset(ptr[i].matrix);
	}
    strcpy(ptr[0].name, "MAT_A");
    strcpy(ptr[1].name, "MAT_B");
    strcpy(ptr[2].name, "MAT_C");
    strcpy(ptr[3].name, "MAT_D");
    strcpy(ptr[4].name, "MAT_E");
    strcpy(ptr[5].name, "MAT_F");
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
	int i,j,k;
	mat tmp;
	reset(tmp.matrix); 
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			for(k = 0; k < SIZE; k++){
				tmp.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
			}
		}
	}
	copy_mat(&tmp, C);
}

void trans_mat(mat *A, mat *B){
	int i,k;
	mat tmp;
	for(i = 0; i < SIZE; i++){
		for(k = 0; k < SIZE; k++){
			tmp.matrix[i][k] = A->matrix[k][i] ;
		}
	}
	copy_mat(&tmp, B);
}

void mul_scalar(mat *A, double s, mat *B){
	int i,k;
	for(i = 0; i < SIZE; i++){
		for(k = 0; k < SIZE; k++){
			B->matrix[i][k] = A->matrix[i][k] * s;
		}
	}
}

void read_mat(mat *A, double values[]){
	int i,k,p;
	p=0;
	for(i = 0; i < SIZE; i++){
		for(k = 0; k < SIZE; k++){
			A->matrix[i][k] = values[p];
			p++;
		}
	}
	print_mat(A);
}

void copy_mat(mat *A, mat *B){
	int i,k;
	for(i = 0; i < SIZE; i++){
		for(k = 0; k < SIZE; k++){
			B->matrix[i][k] = A->matrix[i][k];
		}
	}
}


