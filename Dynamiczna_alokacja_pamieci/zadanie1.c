#include <stdio.h>
#include <stdlib.h>

int main(){

float *tab = malloc(sizeof(float)*100);

for(int i=0; i<100; i++)
  printf("%.2f\n",tab[i] = i);

free(tab);

  return 0;
}
