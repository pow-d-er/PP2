#include "prostokat.h"


bool isRectangle(const point_t* a, const point_t* b, const point_t* c, const point_t* d){
  double cx,cy;
  double dd1,dd2,dd3,dd4;

  cx=(a->x + b->x + c->x + d->x)/4;
  cy=(a->y + b->y + c->y + d->y)/4;

  dd1=pow(cx-a->x,2)+pow(cy-a->y,2);
  dd2=pow(cx-b->x,2)+pow(cy-b->y,2);
  dd3=pow(cx-c->x,2)+pow(cy-c->y,2);
  dd4=pow(cx-d->x,2)+pow(cy-d->y,2);
  return dd1==dd2 && dd1==dd3 && dd1==dd4;
}

rectangle_t* new_rectangle(const point_t* a, const point_t* b, const point_t* c, const point_t* d){

if(isRectangle(a,b,c,d)){
rectangle_t* new = malloc(sizeof(rectangle_t));
new->points = malloc(sizeof(point_t)*4);
new->sections = malloc(sizeof(section_t)*4);

new->points[0] = *a;
new->points[1] = *b;
new->points[2] = *c;
new->points[3] = *d;

for(int i=0; i<3; i++){
  new->sections[i].bPoint = &new->points[i];
  new->sections[i].ePoint = &new->points[i+1];
}

new->sections[3].bPoint = &new->points[3];
new->sections[3].ePoint = &new->points[0];

return new;
}
else return NULL;
};

double calculate_circuit(const rectangle_t* rectangle){
  return  howLong(&rectangle->sections[0]) +
              howLong(&rectangle->sections[1]) +
              howLong(&rectangle->sections[2]) +
              howLong(&rectangle->sections[3]);
};

double calculate_field(const rectangle_t* rectangle){
  return  howLong(&rectangle->sections[0]) *
              howLong(&rectangle->sections[1]);
};

void moveRectangleUp(rectangle_t* rectangle){

for(int i=0; i<4; i++){
  rectangle->points[i].y++;

}

for(int i=0; i<3; i++){
  rectangle->sections[i].bPoint = &rectangle->points[i];
  rectangle->sections[i].ePoint = &rectangle->points[i+1];
}

rectangle->sections[3].bPoint = &rectangle->points[3];
rectangle->sections[3].ePoint = &rectangle->points[0];



};


void moveRectangleDown(rectangle_t* rectangle){

for(int i=0; i<4; i++){
  rectangle->points[i].y--;

}

for(int i=0; i<3; i++){
  rectangle->sections[i].bPoint = &rectangle->points[i];
  rectangle->sections[i].ePoint = &rectangle->points[i+1];
}

rectangle->sections[3].bPoint = &rectangle->points[3];
rectangle->sections[3].ePoint = &rectangle->points[0];



};

void moveRectangleRight(rectangle_t* rectangle){

for(int i=0; i<4; i++){
  rectangle->points[i].x++;

}

for(int i=0; i<3; i++){
  rectangle->sections[i].bPoint = &rectangle->points[i];
  rectangle->sections[i].ePoint = &rectangle->points[i+1];
}

rectangle->sections[3].bPoint = &rectangle->points[3];
rectangle->sections[3].ePoint = &rectangle->points[0];

};

void moveRectangleLeft(rectangle_t* rectangle){

for(int i=0; i<4; i++){
  rectangle->points[i].x--;

}

for(int i=0; i<3; i++){
  rectangle->sections[i].bPoint = &rectangle->points[i];
  rectangle->sections[i].ePoint = &rectangle->points[i+1];
}

rectangle->sections[3].bPoint = &rectangle->points[3];
rectangle->sections[3].ePoint = &rectangle->points[0];
};



void scale_rectangle(const rectangle_t* rectangle, float scale){
  for(int i=0; i<4; i++){
    rectangle->points[i].x *= scale;
    rectangle->points[i].y *= scale;
  }

  for(int i=0; i<3; i++){
    rectangle->sections[i].bPoint = &rectangle->points[i];
    rectangle->sections[i].ePoint = &rectangle->points[i+1];
  }

  rectangle->sections[3].bPoint = &rectangle->points[3];
  rectangle->sections[3].ePoint = &rectangle->points[0];
};

rectangle_t* compare_rectangles(const rectangle_t* a, const rectangle_t* b){

  rectangle_t* bigger = malloc(sizeof(rectangle_t));
  if(calculate_field(a) == calculate_field(b) ) bigger = NULL;
  else if(calculate_field(a) > calculate_field(b) )  *bigger = *a;
  else *bigger = *b;

  return bigger;
};
