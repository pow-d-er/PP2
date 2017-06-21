#include "punkt.h"

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

printf("Punkty posortowane wzgledem y malejaco: \n");
for(int i=0; i<10; i++){
wyswietl(sortuj_wzgledem_y_malejaco(&point[i]));
printf("\n");
}

printf("Punkty posortowane wzgledem x malejaco: \n");
for(int i=0; i<10; i++){
wyswietl(sortuj_wzgledem_x_malejaco(&point[i]));
printf("\n");
}

najdalszy = najdalej_od_wszystkich(point);
printf("Najdalej położony punkt od wszystkich: "); wyswietl(&najdalszy);
printf("\nOdległość do najbliższego punktu: %.2f\n", najdalszy.max);

  return 0;
}
