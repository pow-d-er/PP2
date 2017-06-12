#ifndef punkt_h
#define punkt_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct{
  int x;
  int y;
  double max;
}point_t;


void przesun_w_poziomie(point_t* p, int dx);
void przesun_w_pionie(point_t* p, int dy);
double oblicz_odleglosc(const point_t* p1, const point_t* p2);
void zapisz_do_pliku(const char *path,const point_t *points);
point_t *wczytaj_z_pliku(const char* path);
point_t* sortuj_wzgledem_x_malejaco(const point_t *points);
point_t* sortuj_wzgledem_y_malejaco(const point_t *points);
point_t sortuj_wzgledem_max_malejaco(const point_t *points);
point_t najdalej_od_wszystkich(point_t *points);

#endif
