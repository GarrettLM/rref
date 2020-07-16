#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"
#include "matrix.h"
#include "vector.h"

//This function is used to allocate memory for a matrix. As input it requires a
//unintialized pointer to a matrix and the number of columns and rows the matrix
//will hold. The pointer to the matrix will be modified by this function.
//Returns an alias pointer to the matrix or NULL if the allocation failed. 
Fraction** initializeMatrix(Fraction *matrix[], size_t numColumns, size_t numRows) {
	*matrix = (Fraction*) malloc(numRows * numColumns * sizeof(Fraction));
	/*if (*matrix == NULL) return *matrix;

	size_t rowSize = numColumns * sizeof(Fraction);
	matrix[0] = (Fraction*) malloc(numRows * rowSize);
	if (matrix[0] == NULL) {
		free(matrix);
		return *matrix;
	}

	for (size_t i = 1; i < numRows; i++) {
		matrix[i] = matrix[i - 1] + numColumns;
	}*/

	return *matrix;
}

//This function frees up the memory for a matrix and sets the matrix pointer to NULL.
void deallocateMatrix(Fraction *matrix[]) {
	//free(matrix[0]);
	free(*matrix);
	*matrix = NULL;
}

//This function parses a matrix from an unput file and adds them to an already initialized matrix.
void parseMatrix(Fraction matrix[], size_t numColumns, size_t numRows, FILE *infile) {
	char buffer[BUFF_SIZE];
	for (size_t i = 0; i < numRows; i++) {
		for (size_t j = 0; j < numColumns; j++) {
			if (fscanf(infile, "%s", buffer) > BUFF_SIZE) {
				printf("Error: Entries in the matrix need to be less than %d characters long!\n", BUFF_SIZE);
				exit(1);
			}
			parseFraction(&matrix[(i * numColumns) + j], buffer);
		}
	}
}

//This function prints a matrix to standard output.
void printMatrix(Fraction matrix[], size_t numColumns, size_t numRows) {
	for (size_t i = 0; i < numRows; i++) {
		for (size_t j = 0; j < numColumns; j++) {
			printFraction(&matrix[(i * numColumns) + j]);
			printf("\t");
		}
		printf("\n");
	}
}

//This function prints a matrix to an outputfile.
void fprintMatrix(Fraction matrix[], size_t numColumns, size_t numRows, FILE *outfile) {
	for (size_t i = 0; i < numRows; i++) {
		for (size_t j = 0; j < numColumns; j++) {
			fprintFraction(&matrix[(i * numColumns) + j], outfile);
			fprintf(outfile, "\t");
		}
		fprintf(outfile, "\n");
	}
}

//This function will transform a matrix to its reduced row echelon form.
//The original matrix will be modified by this function.
void rref(Fraction matrix[], size_t numColumns, size_t numRows) {
	Fraction tempfract;
	for (size_t i = 0; i < numRows; i++) {
		for (size_t j = i + 1; isZero(&matrix[(i * numColumns) + i]); j++) {
			if (isZeroVector(&matrix[i * numColumns], numColumns)) {
				numRows--;
				/*Fraction *tempptr = matrix[numRows];
				matrix[numRows] = matrix[i];
				matrix[i] = tempptr;*/
				swapVectors(&matrix[i * numColumns], &matrix[numRows * numColumns], numColumns);
				if (numRows == i) return;
			} else {
				/*Fraction *tempptr = matrix[j];
				matrix[j] = matrix[i];
				matrix[i] = tempptr;*/
				swapVectors(&matrix[i * numColumns], &matrix[j * numColumns], numColumns);
			}
		}

		getInverse(&matrix[(i * numColumns) + i], &tempfract);
		multiplyVector(&matrix[i * numColumns], numColumns, &tempfract);

		for (size_t j = 0; j < numRows; j++) {
			if (j == i) continue;
			tempfract.numerator = 0;
			tempfract.denominator = 1;
			addFraction(&tempfract, &matrix[(j * numColumns) + i]);
			subVector(&matrix[j * numColumns], &matrix[i * numColumns], numColumns, &tempfract);
		}
	}
}
