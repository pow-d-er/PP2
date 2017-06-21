#include "punkt.h"

void przesun_w_poziomie(point_t* p, int dx){
    p->x = dx;
}

void przesun_w_pionie(point_t* p, int dy){
    p->y = dy;
}

double oblicz_odleglosc(const point_t* p1, const point_t* p2){
  double odleglosc = sqrt(pow(p2->x - p1->x,2)+pow(p2->y - p1->y,2));

  return odleglosc;
}

void zapisz_do_pliku(const char *path,const point_t *points){
  FILE *fp = fopen(path, "wb");

  fwrite(points,sizeof(point_t),10,fp);


  fclose(fp);
}

point_t *wczytaj_z_pliku(const char* path){
  FILE *fp = fopen(path, "rb");

  point_t *points = malloc(sizeof(point_t)*10);
  point_t point[10];
if(fp){
  fread(&point, sizeof(point_t), 10, fp);
for(int i=0; i<10; i++)
  points[i] = point[i];

}else printf("Nie mozna odczytac pliku");

  fclose(fp);

return points;
}

point_t* sortuj_wzgledem_x_malejaco(const point_t *points){
    point_t *sorted = malloc(sizeof(point_t)*10);
    point_t x;

    for(int i=0; i<10; i++)
      sorted[i] = points[i];

    for(int i=0; i<10; i++)
      for(int j=0; j<9; j++)
        if(sorted[j].x<sorted[j+1].x){
          x = sorted[j];
          sorted[j] = sorted[j+1];
          sorted[j+1] = x;
        }

return sorted;
}

point_t* sortuj_wzgledem_y_malejaco(const point_t *points){
    point_t *sorted = malloc(sizeof(point_t)*10);
    point_t y;

    for(int i=0; i<10; i++)
      sorted[i] = points[i];

    for(int i=0; i<10; i++)
      for(int j=0; j<9; j++)
        if(sorted[j].y<sorted[j+1].y){
          y = sorted[j];
          sorted[j] = sorted[j+1];
          sorted[j+1] = y;
        }

        wyswietl

return sorted;
}

point_t sortuj_wzgledem_max_malejaco(const point_t *points){

      point_t *sorted = malloc(sizeof(point_t)*10);
      point_t max;

      for(int i=0; i<10; i++)
        sorted[i] = points[i];

      for(int i=0; i<10; i++)
        for(int j=0; j<9; j++)
          if(sorted[j].max<sorted[j+1].max){
            max = sorted[j];
            sorted[j] = sorted[j+1];
            sorted[j+1] = max;
          }

return sorted[0];
};

point_t najdalej_od_wszystkich(point_t *points){
point_t* p = malloc(sizeof(point_t));
p->odleglosc = 0;
double helper;

for(int i=0; i<10; i++){
points[i].odleglosc = 0;
  for(int j=0; j<10; j++){
    if(j == i) continue;
    points[i].odleglosc = oblicz_odleglosc(&points[i],&points[j]);
  }
}

};

void wyswietl(point_t* point){

  printf("(%d,%d)",point->x, point->y);

};
