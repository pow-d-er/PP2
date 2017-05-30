#include <stdio.h>
#include <stdlib.h>

float* alokuj(int N){

  float *tab = malloc(sizeof(float)*N);

  return tab;
};

int main(){

int n;
float *tab;
printf("Podaj liczbe elementów: ");
tab = alokuj(scanf("%d",&n));

for(int i=0; i<n; i++)
  printf("%.2f\n",tab[i]);

  return 0;
}
