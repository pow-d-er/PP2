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

tab_t* create_new_tab(const int size){
    tab_t* new = malloc(sizeof(tab_t));
      new->size = size;
      new->tab = malloc(sizeof(zespolona_t)*size);
      new->howMuch = 0;
      return new;
};

void add_to_tab(tab_t* tab, const zespolona_t* a){
  if(tab->howMuch == tab->size) printf("Tablica przepelniona, nie mozna dodac elementu.\n");
  else{
  zespolona_t* b = malloc(sizeof(zespolona_t));
  *b = *a;
  tab->tab[tab->howMuch] = *b;
  tab->howMuch++;
  free(b);
}

};

void display_tab(const tab_t* tab){
  for(int i=0; i<tab->howMuch;i++){
    display(&tab->tab[i]);
    printf("\n");
  }
};


tab_t* sort(const tab_t* tab){


    tab_t* sorted_tab = malloc(sizeof(tab_t));
    sorted_tab->howMuch = tab->howMuch;
    sorted_tab->tab = tab->tab;
    sorted_tab->size = tab->size;
    zespolona_t* helper = malloc(sizeof(zespolona_t));


  for(int i=0; i<sorted_tab->howMuch-1; i++){
    for(int j=0; j<sorted_tab->howMuch-1; j++){
      if(calculate_mod(&sorted_tab->tab[j+1])<(calculate_mod(&sorted_tab->tab[j]))){
        *helper = sorted_tab->tab[j];
        sorted_tab->tab[j] = sorted_tab->tab[j+1];
        sorted_tab->tab[j+1] = *helper;
      }
    }
  }
  free(helper);

return sorted_tab;

};

zespolona_t* find_min(const tab_t* tab){
return &(sort(tab)->tab[0]);
};

zespolona_t* find_max(const tab_t* tab){
   return &(sort(tab)->tab[tab->howMuch-1]);
};
