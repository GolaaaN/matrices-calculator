#include <stdio.h>
#include <string.h>
#define SIZE 4

struct mat{
    char name[6];
    double matrix[4][4]; 
};

typedef struct mat mat;

void init_matrix(mat *ptr);
void print_mat(mat a);
void reset(double matrix[4][4]);



