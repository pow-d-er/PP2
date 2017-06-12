#include "kolejka.h"

int main(){

point_t * point;

queue_t *q = malloc(sizeof(queue_t));
if(queue_create(q,10)){
queue_push(q,5,3);
queue_push(q,6,2);
queue_push(q,7,1);
queue_push(q,8,0);
queue_push(q,9,-1);
}

queue_print(q);
point = queue_pop(q);
printf("Usuwany element: (%d,%d)\n",point->x,point->y);
queue_print(q);

printf("Dodaję element (13,9) z przodu i wyswietlam kolejke: \n");
queue_push_front(q,13,9);
queue_print(q);

printf("Usuwam element z konca kolejki i wywswietlam ja: \n");
queue_pop_back(q);
queue_print(q);

printf("Sprawdzam czy istnieje w kolejce element (7,1): \n");
printf("Bool: %d",element_exist(q,7,1));

  return 0;
}
