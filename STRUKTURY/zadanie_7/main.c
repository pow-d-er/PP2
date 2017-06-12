#include "prostokat.h"

void main(){
srand((unsigned int)time(NULL));


point_t* points = malloc(sizeof(point_t)*4);
              for(int j=0; j<4; j++){
                points[j].x = 1;
                points[j].y = 1;
              }

int n;

printf("Podaj liczbe prostokatow, ktore chcesz stworzyc: \n");
scanf("%d",&n);

rectangle_t* rectangles = (rectangle_t*)malloc(sizeof(rectangle_t)*n);
for(int i=0; i<n; i++){
rectangles[i].points = (point_t*)malloc(sizeof(point_t)*4);
rectangles[i].sections = (section_t*)malloc(sizeof(section_t)*4);
}

for(int i=0; i<n; i++){
        while(!(&rectangles[i])){
              for(int j=0; j<4; j++){
                points[j].x = rand()%20;
                points[j].y = rand()%20;
              }
                        rectangles[i] = *new_rectangle(&points[0],&points[1],&points[2],&points[3]);
        }
}



}
