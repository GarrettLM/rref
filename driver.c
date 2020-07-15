#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"
#include "vector.h"
#include "matrix.h"

int main(int argc, char *argv[]) {

	if (argc == 1) {
		printf("Error: Enter the name of a file with a matrix as an argumnet.\n");
		exit(1);
	}

	FILE *infile = fopen(argv[1], "r");
	if (infile == NULL) {
		printf("Error: The file %s was not found!\n", argv[1]);
		exit(1);
	}

	size_t numRows, numColumns;

	printf("Getting dimensions of the matrix from the file\n");
	fscanf(infile, "%ld,%ld", &numColumns, &numRows);
	printf("Dimension from the matrix are: %ld,%ld\n", numColumns, numRows);
	Fraction ***matrix;
	printf("Initializing the matrix\n");
	if (initializeMatrix(matrix, numColumns, numRows) == NULL) {
		printf("Error: Failed to initialize memory!\n");
		exit(1);
	}
	printf("Matrix initialized\nParsing the matrix\n");
	parseMatrix(matrix, numColumns, numRows, infile);
	printf("Matrix parsed\nClosing file\n");
	fclose(infile);
	printMatrix(matrix, numColumns, numRows, infile);
	printf("Performing rref\n");
	rref(matrix, numColumns, numRows);
	printf("rref performed\n");
	printMatrix(matrix, numColumns, numRows, infile);
}
