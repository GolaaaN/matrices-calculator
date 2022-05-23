#ifndef MAT_H
#define MAT_H
#include <stdio.h>
#include <string.h>
#define SIZE 4
#define MAT_NUM 6

struct mat{
    char name[6];
    double matrix[4][4]; 
};
typedef struct mat mat;

/**
 * initializes the matrices.
 * param - mat pointer to the array.
 * return.
 */
void init_matrix(mat *ptr);
/**
 * prints the matrix.
 * param - pointer to matrix.
 * return.
 */
void print_mat(mat *a);
/**
 * sums mat A & B and puts it in mat C.
 * param - pointer to 3 matrices
 * return.
 */
void add_mat(mat *A, mat *B, mat *C);
/**
 * subs mat A & B and puts it in mat C.
 * param - pointer to 3 matrices
 * return.
 */
void sub_mat(mat *A, mat *B, mat *C);
/**
 * multiplys mat A & B and puts it in mat C.
 * param - pointer to 3 matrices
 * return.
 */
void mul_mat(mat *A, mat *B, mat *C);
/**
 * transformates mat A and puts it in mat C.
 * param - pointer to 2 matrices.
 * return.
 */
void trans_mat(mat *A, mat *B);
/**
 * multiply A by scalar and puts it in B.
 * param - pointer to matrix, scalar, pointer to matrix.
 * return.
 */
void mul_scalar(mat *A, double s, mat *B);
/**
 * reads to mat A the values.
 * param - pointer to matrix, values array to save the values.
 * return.
 */
void read_mat(mat *A, double values[]);
/**
 * resets matrix.
 * param - pointer to matrix.
 * return.
 */
void reset(double matrix[4][4]);
/**
 * copies mat a to mat b matrix.
 * param - pointer to matrix, pointer to matrix.
 * return.
 */
void copy_mat(mat *A, mat *B);

#endif

