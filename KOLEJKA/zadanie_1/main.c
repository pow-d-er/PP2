#include "kolejka.h"

int main(){

queue_t *q = malloc(sizeof(queue_t));
if(queue_create(q,10)){
queue_push(q,5);
queue_push(q,6);
queue_push(q,7);
queue_push(q,8);
queue_push(q,9);
queue_push(q,10);
queue_push(q,11);
queue_push(q,12);
queue_push(q,13);
queue_push(q,14);
queue_push(q,15);
queue_push(q,16);

queue_print(q);

printf("Usuwany element: %d\n",queue_pop(q));
printf("Usuwany element: %d\n",queue_pop(q));
printf("Usuwany element: %d\n",queue_pop(q));

queue_print(q);
}

  return 0;
}
