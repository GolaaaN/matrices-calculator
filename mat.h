#ifndef MAT_H
#define MAT_H
#include <stdio.h>
#include <string.h>
#define SIZE 4


struct mat{
    char name[6];
    double matrix[4][4]; 
};


typedef struct mat mat;

void init_matrix(mat *ptr);
void print_mat(mat *a);
void add_mat(mat *A, mat *B, mat *C);
void sub_mat(mat *A, mat *B, mat *C);
void mul_mat(mat *A, mat *B, mat *C);
void trans_mat(mat *A, mat *B);
void read_mat(mat *A, double values[]);
void reset(double matrix[4][4]);

#endif

