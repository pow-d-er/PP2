#ifndef kolejka_h
#define kolejka_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{

  int* tab;
  int index;
  int howMuch;
  int size;
}queue_t;


bool queue_create(queue_t *q, int size);
void queue_push(queue_t * q, int value);
int queue_pop(queue_t * q);
bool queue_empty(const queue_t * q);
int queue_size(const queue_t * q);
void queue_print(const queue_t * q);
#endif
