#include "highscore.h"

int main(){
srand((unsigned int)time(NULL));
int n,index;
double score;
char* alphabet = "abcdefghijklmnopqrstuvwxyz";

printf("Ile rekordow chcesz stworzyc?: ");
scanf("%d",&n);

tab_highscore_t *tab = new_tab_highscore(n);
char* nickname = malloc(sizeof(char)*10);
for(int i=0; i<n; i++){
int howLong = rand()%10 + 1;
  for(int j=0; j<howLong; j++){
  nickname[j] = alphabet[rand()%24];
  }
add_record(tab,nickname,(double) rand()/((double)(RAND_MAX/50)));
}

display_highscores(tab);
printf("\nPodaj nickname: ");
scanf("%s",nickname);
printf("Podaj wynik: ");
scanf("%lf",&score);
add_record(tab,nickname,score);
display_highscores(tab);
save_highscore("highscores.txt",tab);
printf("\nWczytane wyniki: \n");
display_highscores(load_highscore("highscores.txt"));
printf("\nPodaj indeks rekordu, który chcesz usunac: ");
scanf("%d", &index);
delete_record(tab,index);
printf("\nWyniki po usunieciu rekordu o indeksie %d: \n",index);
display_highscores(tab);

  return 0;

}
