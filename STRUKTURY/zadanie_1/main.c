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
sortuj_wzgledem_y_malejaco(point);
sortuj_wzgledem_x_malejaco(point);
najdalszy = najdalej_od_wszystkich(point);
printf("Najdalej położony punkt od wszystkich: (%d,%d). Odległość do najbliższego punktu: %.2f\n",najdalszy.x,najdalszy.y,najdalszy.max);

  return 0;
}
