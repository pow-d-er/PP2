#ifndef dzialania_h
#define dzialania_h
#include <stdlib.h>
#include <stdio.h>

typedef float (* type)(float,float);

float calculate(float a, float b, type calc);


float sum(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float division(float a, float b);


#endif
