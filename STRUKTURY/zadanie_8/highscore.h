#ifndef highscore_h
#define highscore_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
  double score;
  char *nickname;
}highscore_t;

typedef struct{
highscore_t* highscore;
int howMuch;
int size;
}tab_highscore_t;

tab_highscore_t* new_tab_highscore(int size);
void add_record(tab_highscore_t* tab,const char* nickname, double score);
void delete_record(tab_highscore_t* tab, int index);
void sort_highscores(tab_highscore_t* tab);
void save_highscore(const char *path, const tab_highscore_t* tab);
tab_highscore_t* load_highscore(const char *path);
void display_highscores(tab_highscore_t* tab);

#endif
