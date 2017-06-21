#ifndef zespolone_h
#define zespolone_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{

  int rzeczywista;
  int urojona;

}zespolona_t;

zespolona_t* create_new(int rzeczywista, int urojona);
zespolona_t* sum(zespolona_t* a, zespolona_t* b);
zespolona_t* subtract(zespolona_t* a, zespolona_t* b);
zespolona_t* multiply(zespolona_t* a, zespolona_t* b);
float calculate_mod(zespolona_t* a);
zespolona_t* load(const char* path);
void save(const char* path, zespolona_t* a);
void display(zespolona_t* a);

#endif
