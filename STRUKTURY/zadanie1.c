#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct{
  int x;
  int y;
  double max;
}point_t;


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

  // for(int i=0; i<10; i++){
  //   printf("%d ",points[i].x);
  //   printf("%d\n",points[i].y);
  // }

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

  // for(int i=0; i<10; i++){
  //   printf("%d ",point[i].x);
  //   printf("%d\n",point[i].y);
  // }
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
}

point_t najdalej_od_wszystkich(point_t *points){
double helper;

for(int i=0; i<10; i++){
points[i].max = 0;
  for(int j=0; j<10; j++){
    if(j == i) continue;
    if(points[i].max<(helper = oblicz_odleglosc(&points[i],&points[j]))) points[i].max = helper;
  }
}

return sortuj_wzgledem_max_malejaco(points);

}


int main(){
srand(time(NULL));

point_t najdalszy;
point_t point[10];

for(int i=0; i<10; i++){
  point[i].x = rand()%20;
  point[i].y = rand()%20;
}

przesun_w_poziomie(&point[5],20);
przesun_w_pionie(&point[5],20);
zapisz_do_pliku("punkty.txt",point);
wczytaj_z_pliku("punkty.txt");
sortuj_wzgledem_y_malejaco(point);
sortuj_wzgledem_x_malejaco(point);
najdalszy = najdalej_od_wszystkich(point);
printf("Najdalej położony punkt od wszystkich: %d,%d. Odległość do najbliższego punktu: %.2f\n",najdalszy.x,najdalszy.y,najdalszy.max);

  return 0;
}
