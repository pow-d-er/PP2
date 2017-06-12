#include "odcinki.h"

int main(){
  srand((unsigned int)time(NULL));
  section_t* section = new_section(1,1,4,4);

point_t* points = designate_points(section);
for(int i = 0;  i<abs(section->ePoint->x - section->bPoint->x)+1; i++){
  printf("(%.2f,%.2f)\n", points[i].x,points[i].y);
}

  return 0;
}
