#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

double *d = malloc(sizeof(double));
*d = M_PI;

printf("Wartość: %f\n",*d);
printf("Adres: %p",d);
  return 0;
}
