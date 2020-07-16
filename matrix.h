#ifndef MATRIX_H
#define MATRIX_H

//Sets the size for the buffer used in the parseMatrix function
#define BUFF_SIZE 128
//typedef Fraction** Matrix;

//This function is used to allocate memory for a matrix. As input it requires a
//unintialized pointer to a matrix and the number of columns and rows the matrix
//will hold. The pointer to the matrix will be modified by this function.
//Returns an alias pointer to the matrix or NULL if the allocation failed. 
Fraction** initializeMatrix(Fraction *matrix[], size_t numColumns, size_t numRows);
//This function frees up the memory for a matrix and sets the matrix pointer to NULL.
void deallocateMatrix(Fraction *matrix[]);
//This function parses a matrix from an unput file and adds them to an already initialized matrix.
void parseMatrix(Fraction matrix[], size_t numColumns, size_t numRows, FILE *infile);
//This function prints a matrix to standard output.
void printMatrix(Fraction matrix[], size_t numColumns, size_t numRows);
//This function prints a matrix to an outputfile.
void fprintMatrix(Fraction matrix[], size_t numColumns, size_t numRows, FILE *outfile);
//This function will transform a matrix to its reduced row echelon form.
//The original matrix will be modified by this function.
void rref(Fraction matrix[], size_t numColumns, size_t numRows);

#endif //MATRIX_H
