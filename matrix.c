#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"
#include "matrix.h"
#include "vector.h"

Fraction** initializeMatrix(Fraction ***matrix, size_t numColumns, size_t numRows) {
	*matrix = (Fraction**) malloc(numRows * sizeof(Fraction*));
	if (matrix == NULL) return *matrix;

	size_t rowSize = numColumns * sizeof(Fraction);
	matrix[0] = (Fraction*) malloc(numRows * rowSize);
	if (matrix[0] == NULL) {
		free(matrix);
		return *matrix;
	}

	for (size_t i = 1; i < numRows; i++) {
		matrix[i] = matrix[i - 1] + numColumns;
	}

	return *matrix;
}

void parseMatrix(Fraction ***matrix, size_t numColumns, size_t numRows, FILE *infile) {
	char buffer[BUFF_SIZE];
	for (size_t i = 0; i < numRows; i++) {
		for (size_t j = 0; j < numColumns; j++) {
			if (fscanf(infile, "%s", buffer) > BUFF_SIZE) {
				printf("Error: Entries in the matrix need to be less than %d characters long!\n", BUFF_SIZE);
				exit(1);
			}
			parseFraction(&matrix[i][j], buffer);
		}
	}
}

void printMatrix(Fraction ***matrix, size_t numColumns, size_t numRows, FILE *outfile) {
	for (size_t i = 0; i < numRows; i++) {
		for (size_t j = 0; j < numColumns; j++) {
			printFraction(&matrix[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}

void rref(Fraction ***matrix, size_t numColumns, size_t numRows) {
	Fraction tempfract;
	for (size_t i = 0; i < numRows; i++) {
		for (size_t j = i + 1; isZero(&matrix[i][i]); j++) {
			if (isZeroVector(matrix[i], numColumns)) {
				numRows--;
				Fraction *tempptr = matrix[numRows];
				matrix[numRows] = matrix[i];
				matrix[i] = tempptr;
				if (numRows == i) return;
			} else {
				Fraction *tempptr = matrix[j];
				matrix[j] = matrix[i];
				matrix[i] = tempptr;
			}
		}

		getInverse(&matrix[i][i], &tempfract);
		multiplyVector(matrix[i], numColumns, &tempfract);

		for (size_t j = 0; j < numRows; j++) {
			if (j == i) continue;
			tempfract.numerator = 0;
			tempfract.denominator = 1;
			addFraction(&tempfract, &matrix[j][i]);
			subVector(matrix[j], matrix[i], numColumns, &tempfract);
		}
	}
}
