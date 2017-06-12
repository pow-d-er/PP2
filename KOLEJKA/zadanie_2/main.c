#include "kolejka.h"

int main(){

queue_t *q = malloc(sizeof(queue_t));
if(queue_create(q,10)){
queue_push(q,5);
queue_push(q,6);
queue_push(q,7);
queue_push(q,8);
queue_push(q,9);
}

queue_print(q);
printf("Usuwany element: %d\n",queue_pop(q));
queue_print(q);

printf("Dodaję element 13 i wyswietlam kolejke: \n");
queue_push_front(q,13);
queue_print(q);

printf("Usuwam element z konca kolejki i wywswietlam ja: \n");
queue_pop_back(q);
queue_print(q);

  return 0;
}
