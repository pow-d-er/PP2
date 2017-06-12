#ifndef biblioteka_t
#define biblioteka_t
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
enum type{
                    Satire = 0,
                    Horror = 1,
                    Mystery = 2,
                    History = 3,
                    Science = 4,
                    Poetry = 5,
                    Fantasy = 6,
                    Biographies = 7,
                    Science_fiction = 8,
                 };
static char* enumStrings[] = {"Satire","Horror","Mystery","History","Science","Poetry","Fantasy", "Biographies","Science fiction"};

typedef struct{

char* authorName;
char* title;
enum type type;
short year;

}book_t;

typedef struct{
  book_t* books;
  int howMuch;
  int size;
}library_t;

library_t* new_library(int size);
void add_record(library_t* library, char* authorName, char* title, short type, short year);
void remove_record(library_t* library, int index);
void display(const library_t* library);
library_t* sort_by_type(const library_t* library);
library_t* sort_by_title(const library_t* library);
library_t* sort_by_authorName(const library_t* library);
library_t* sort_by_year(const library_t* library);
library_t* find_authorName(const library_t* library,const char* authorName);
library_t* find_type(const library_t* library, short type);


#endif
