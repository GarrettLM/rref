#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "fraction.c"
#include "vector.c"

#define BUFF_SIZE 128
//typedef Fraction** Matrix;

Fraction** initializeMatrix(Fraction ***matrix, size_t numColumns, size_t numRows);
void parseMatrix(Fraction ***matrix, size_t numColumns, size_t numRows, FILE *infile);
void printMatrix(Fraction ***matrix, size_t numColumns, size_t numRows, FILE *outfile);
void rref(Fraction ***matrix, size_t numColumns, size_t numRows);

#endif //MATRIX_H
