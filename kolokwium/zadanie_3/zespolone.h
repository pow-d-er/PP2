#ifndef zespolone_h
#define zespolone_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{

  int rzeczywista;
  int urojona;

}zespolona_t;

typedef struct{
  int size;
  zespolona_t* tab;
  int howMuch;
}tab_t;

zespolona_t* create_new(int rzeczywista, int urojona);
zespolona_t* sum(zespolona_t* a, zespolona_t* b);
zespolona_t* subtract(zespolona_t* a, zespolona_t* b);
zespolona_t* multiply(zespolona_t* a, zespolona_t* b);
float calculate_mod(zespolona_t* a);
zespolona_t* load(const char* path);
void save(const char* path, zespolona_t* a);
void display(zespolona_t* a);

tab_t* create_new_tab(const int size);
void add_to_tab(tab_t* tab, const zespolona_t* a);
void display_tab(const tab_t* tab);
tab_t* sort(const tab_t* tab);
zespolona_t* find_min(const tab_t* tab);
zespolona_t* find_max(const tab_t* tab);

#endif
