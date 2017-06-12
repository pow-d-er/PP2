#include "kolejka.h"

bool queue_create(queue_t *q, int size){

  q->tab = (point_t*) malloc(sizeof(point_t)*size);
  if(q->tab == NULL)  return false;

  q->size = size;
  q->howMuch = 0;
  q->index = 0;
  return true;
}

void queue_push(queue_t * q, int x, int y){
  q->tab[q->howMuch + q->index].x = x;
  q->tab[q->howMuch + q->index].y = y;
  q->howMuch++;
    if(q->howMuch + q->index > q->size-1){
        q->tab = (point_t*)realloc(q->tab, sizeof(point_t)*q->size*2);
        q->size = q->size*2;
}
}

point_t* queue_pop(queue_t * q){
  if(queue_empty(q)){
    printf("Ta kolejka jest pusta!");
    return 0;
  }
  point_t* value = &q->tab[q->index];
  q->index++;
  q->howMuch--;
  return value;
}

bool queue_empty(const queue_t * q){
    if(q->howMuch == 0) return true;
    else return false;
}

int queue_size(const queue_t * q){
  return q->howMuch;
}

void queue_print(const queue_t * q ){
  queue_t q2;
  q2 = *q;
  for(int i=q2.index; i<q2.howMuch+q2.index; i++)
  printf("(%d,%d)\n",q2.tab[i].x,q2.tab[i].y);
}

void queue_push_front(queue_t * q, int x, int y){

    if(q->index-1<0){
      printf("Queue underflow\n");
    }else{
      q->index--;
    q->tab[q->index].x = x;
    q->tab[q->index].y = y;
    q->howMuch++;
  }
};

point_t* queue_pop_back(queue_t * q){
    if(queue_empty(q)){
      printf("Ta kolejka jest pusta!");
      return 0;
    }
    point_t* value = &q->tab[q->howMuch];
    q->howMuch--;
    return value;
};

bool element_exist(queue_t* q, int x, int y){

  
  for(int i=0; i<q->howMuch; i++)
    if(q->tab[i].x == x && q->tab[i].y == y ) return true;

};
