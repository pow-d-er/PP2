#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct
{
    char nick[100];
    int wynik;
}hs_t;

hs_t *dodaj(hs_t *wsk, int ktory)
{
    char nick;
    int wynik;
    printf("Wprowadz nick:");
    scanf("%s",&nick);
    printf("Wprowadz wynik:");
    scanf("%d",&wynik);

    strcpy(wsk[ktory].nick,&nick);
    wsk[ktory].wynik = wynik;
}

hs_t *sortuj(hs_t *wsk, int ile)
{
    int i,j,temp_w;
    char temp_n[100];

    for(i = ile-1 ;i > 0;i--)
    {
        for(j=ile-1;j>0;j--)
        {
            if(wsk[j].wynik > wsk[j-1].wynik)
            {
                temp_w = wsk[j].wynik;
                wsk[j].wynik = wsk[j-1].wynik;
                wsk[j-1].wynik = temp_w;

                strcpy(temp_n,wsk[j].nick);
                strcpy(wsk[j].nick,wsk[j-1].nick);
                strcpy(wsk[j-1].nick,temp_n);
            }
        }
    }
return wsk;
}

void wyswietl(hs_t *wsk, int ile)
{
    int i;
    printf("\n  !HIGHSCORE!");
    for(i=0;i<ile;i++)
    {

        printf("\n%d: %s -> %d",i+1,wsk[i].nick,wsk[i].wynik);
    }

}

int main()
{
    srand((unsigned int)time(NULL));
    int ile,i,j,jak;
    printf("Ile wynikow chcesz wprowadzic?");
    scanf("%d",&ile);
    hs_t tab[ile];
    hs_t *wsk = tab;
    wsk = (hs_t*) malloc(   ile  *  ( sizeof(int)+sizeof(char) )     );
    printf("Chcesz rekordy wprowadzic samoddzielnie(0) czy losowo(!=0)");
    scanf("%d",&jak);
    if(jak == 0)
    {
        for(i=0;i < ile; i++)
        {
        printf("\nWprowadz dla %d rekordu\n",i+1);
        dodaj(wsk,i);
        }
    }
    else
    {
        for(j = 0;j<ile;j++)
        {
        int liczba;
        liczba = 5 + rand()%20;
        char napis[liczba+1];

        for(i = 0;i<liczba;i++)
        {
          int w =1 + rand()%23;
            char *znaki = "abcdefghijklmnopqrstuwxyz";
            napis[i] = znaki[w-1];
        }
        napis[liczba] = '\0';
        strcpy(wsk[j].nick,napis);
        wsk[j].wynik = 1 + rand()%50;

        }


    }

printf("\nWprowadzone rekordy:");
wyswietl(wsk,ile);
printf("\nSORTOWANIE WYNIKOW:");
wyswietl(sortuj(wsk,ile),ile);






    return 0;
}
