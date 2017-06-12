#include "prostokat.h"

int main(){

point_t* points = malloc(sizeof(point_t)*4);
points[0] = *create_point(-2,2);
points[1] = *create_point(2,2);
points[2] = *create_point(2,-2);
points[3] = *create_point(-2,-2);

rectangle_t* r = new_rectangle(&points[0],&points[1],&points[2],&points[3]);

if(r){
    printf("Obwód: %.2f\n",calculate_circuit(r));
    printf("Pole: %.2f\n",calculate_field(r));
    scale_rectangle(r,3);
        printf("Po skalowaniu x 3\n");
        printf("Obwód: %.2f\n",calculate_circuit(r));
        printf("Pole: %.2f\n",calculate_field(r));

        points[0] = *create_point(-1,1);
        points[1] = *create_point(1,1);
        points[2] = *create_point(1,-1);
        points[3] = *create_point(-1,-1);
        rectangle_t* x = new_rectangle(&points[0],&points[1],&points[2],&points[3]);

        if(x){
        rectangle_t* c = compare_rectangles(r,x);
        if(c){
          printf("Wspolrzedne wiekszego prostokata: \nA(%.2f,%.2f)\nB(%.2f,%.2f)\nC(%.2f,%.2f)\nD(%.2f,%.2f)\n",
                      c->points[0].x,c->points[0].y,c->points[1].x,c->points[1].y,
                      c->points[2].x,c->points[2].y,c->points[3].x,c->points[3].y);
        }
      }else printf("Podane punkty nie tworzą prostokąta\n");

}else printf("Podane punkty nie tworzą prostokąta\n");

  return 0;
}
