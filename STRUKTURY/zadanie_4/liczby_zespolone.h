#ifndef liczby_zespolone_h
#define liczby_zespolone_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
  double rzeczywista;
  double urojona;
}zesp_t;

zesp_t* lz(double rzeczywista, double urojona);
void ustaw(zesp_t* liczba, double rzeczywista, double urojona);
void wyswietl(zesp_t* liczba);
void dodaj(zesp_t* a, zesp_t* b, zesp_t* wynik);
void odejmij(zesp_t* a, zesp_t* b, zesp_t* wynik);
void pomnoz(zesp_t* a, zesp_t* b, zesp_t* wynik);
double modul(zesp_t* liczba);
double argument(zesp_t* liczba);


#endif
