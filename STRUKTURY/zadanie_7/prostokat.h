#ifndef prostokat_h
#define prostokat_h
#include <stdbool.h>
#include "odcinki.h"

typedef struct{
  point_t* points;
  section_t* sections;
}rectangle_t;

bool isRectangle(const point_t* a, const point_t* b, const point_t* c, const point_t* d);
rectangle_t* new_rectangle(const point_t* a, const point_t* b, const point_t* c, const point_t* d);
double calculate_circuit(const rectangle_t* rectangle);
double calculate_field(const rectangle_t* rectangle);
void moveRectangleUp(rectangle_t* rectangle);
void moveRectangleDown(rectangle_t* rectangle);
void moveRectangleRight(rectangle_t* rectangle);
void moveRectangleLeft(rectangle_t* rectangle);
void scale_rectangle(const rectangle_t* rectangle, float scale);
rectangle_t* compare_rectangles(const rectangle_t* a, const rectangle_t* b);



#endif
