#include "highscore.h"

void sort_highscores(tab_highscore_t* tab){

highscore_t* helper = malloc(sizeof(highscore_t));

for(int i=0; i<tab->howMuch; i++){
  for(int j=0; j<tab->howMuch-1; j++){
      if(tab->highscore[j+1].score > tab->highscore[j].score){
        *helper =  tab->highscore[j];
        tab->highscore[j] = tab->highscore[j+1];
        tab->highscore[j+1] = *helper;
      }
  }
}

};

tab_highscore_t* new_tab_highscore(int size){
  tab_highscore_t* new = malloc(sizeof(tab_highscore_t));
    new->highscore = malloc(sizeof(highscore_t)*size);
    new->size = size;
    new->howMuch = 0;

    return new;
};

void add_record(tab_highscore_t* tab,const char* nickname, double score){
int x = 0;
  highscore_t* new = malloc(sizeof(highscore_t));

while(nickname[x] != '\0'){
  x++;
}

  new->nickname = malloc(sizeof(char)*x+1);
  for(int i=0; i<x; i++)
  new->nickname[i] = nickname[i];
  new->nickname[x+1] = '\0';
  new->score = score;

  tab->highscore[tab->howMuch] = *new;
  tab->howMuch++;
  if(tab->howMuch + 1 > tab->size){
    tab->size *= 2;
     tab->highscore = realloc(tab->highscore,sizeof(highscore_t)*tab->size);
   }

   sort_highscores(tab);
 };

 void delete_record(tab_highscore_t* tab, int index){


    tab->highscore[index] = tab->highscore[tab->howMuch-1];
    tab->howMuch--;
   sort_highscores(tab);
 };

void display_highscores(tab_highscore_t* tab){

  sort_highscores(tab);

    printf("\n\nLp.        Nickname               Score\n");
  for(int i=0; i<tab->howMuch; i++){
  printf("%d.         %s                   %.2f\n",
            i+1,tab->highscore[i].nickname,tab->highscore[i].score);
          }
};

void save_highscore(const char *path, const tab_highscore_t* tab){
  FILE* fp = fopen(path,"wb");

  if(fp){
      fwrite(tab, sizeof(highscore_t), tab->howMuch, fp);
      fclose(fp);
  }else printf("Błąd odczytu pliku");
};

tab_highscore_t* load_highscore(const char *path){
  FILE* fp = fopen(path,"rb");
tab_highscore_t* tab = malloc(sizeof(tab_highscore_t));

  if(fp){
     fread(tab, sizeof(tab_highscore_t), 1, fp);
      fclose(fp);
  }else printf("Błąd odczytu pliku");

  return tab;
};
