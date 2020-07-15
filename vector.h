#ifndef VECTOR_H
#define VECTOR_H
//#include "fraction.h"

//multiplies the vector b by the scalar and adds the resulting vector to a
void addVector(Fraction a[], Fraction b[], size_t size, Fraction *scalar);
//multiplies the vector b by the scalar and subtracts the resulting vector from a
void subVector(Fraction a[], Fraction b[], size_t size, Fraction *scalar);
//multiplies each element in the vector a by the scalar
void multiplyVector(Fraction a[], size_t size, Fraction *scalar);
//returns 1 if all the fractions in a vector are equal to 0
int isZeroVector(Fraction a[], size_t size);

#endif //VECTOR_H
