#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
  int x;
  int y;
}point_t;


void przesun_w_poziomie(point_t* p, int dx){
    p->x = dx;
}

void przesun_w_pionie(point_t* p, int dy){
    p->y = dy;
}

void oblicz_odleglosc(const point_t* p1, const point_t* p2){
  double odleglosc = sqrt(pow(p2->x - p1->x,2)+pow(p2->y - p1->y,2));
}

int main(){

  return 0;
}
