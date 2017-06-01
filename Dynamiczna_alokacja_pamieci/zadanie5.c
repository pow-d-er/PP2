#include <stdio.h>
#include <stdlib.h>


void wyswietl(const int* ptr, int N){

    for(int i=0; i<N; i++)
      printf("%d ",ptr[i]);

}

int* kopia(const int* ptr, int N){
  int *copy = malloc(sizeof(int)*N);

  for(int i=0; i<N; i++)
    copy[i] = ptr[i];

    return copy;
}

int main(){

int tab[] = {1,2,3,4,5,6,7,8,9,10};

wyswietl(tab, 10);
printf("\n");
wyswietl(kopia(tab,10),10);

  return 0;
}
