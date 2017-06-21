#include "zespolone.h"

zespolona_t* create_new(int rzeczywista, int urojona){
  zespolona_t* new = malloc(sizeof(zespolona_t));

  new->rzeczywista = rzeczywista;
  new->urojona = urojona;

  return new;

};

void display(zespolona_t* a){
  printf("(%d + %di)", a->rzeczywista, a->urojona);
};


zespolona_t* sum(zespolona_t* a, zespolona_t* b){
  zespolona_t *sum = malloc(sizeof(zespolona_t));

  sum->rzeczywista = a->rzeczywista + b->rzeczywista;
  sum->urojona = a->urojona + b->urojona;

  return sum;

};

zespolona_t* subtract(zespolona_t* a, zespolona_t* b){
    zespolona_t *sub = malloc(sizeof(zespolona_t));

    sub->rzeczywista = a->rzeczywista - b->rzeczywista;
    sub->urojona = a->urojona - b->urojona;

    return sub;
};

zespolona_t* multiply(zespolona_t* a, zespolona_t* b){
    zespolona_t *mult = malloc(sizeof(zespolona_t));

    mult->rzeczywista = a->rzeczywista * b->rzeczywista;
    mult->urojona = a->urojona * b->urojona;

    return mult;
};

float calculate_mod(zespolona_t* a){
    float mod;

    mod = sqrt(pow(a->rzeczywista,2) + pow(a->urojona,2));

    return mod;
};

void save(const char* path, zespolona_t* a){
  FILE* fp = fopen(path,"wb");
  if(fp){
    fwrite(a,sizeof(zespolona_t),1,fp);
  }else printf("Błąd odczytu pliku");
  fclose(fp);
};

zespolona_t* load(const char* path){
  zespolona_t* a = malloc(sizeof(zespolona_t));
    FILE* fp = fopen(path,"rb");
    if(fp){
      fread(a,sizeof(zespolona_t),1,fp);
    }else printf("Błąd odczytu pliku");
    fclose(fp);

    return a;
};
