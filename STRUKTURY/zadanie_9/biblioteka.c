#include "biblioteka.h"


library_t* new_library(int size){

library_t* library = malloc(sizeof(library_t));
  library->size = size;
  library->howMuch = 0;
  library->books = malloc(sizeof(book_t)*size);

  return library;
};

void add_record(library_t* library, char* authorName,
                            char* title, short type, short year){

book_t* new = malloc(sizeof(book_t));
new->authorName = authorName;
new->title = title;
new->type = type;
new->year = year;

library->books[library->howMuch] = *new;
library->howMuch++;
if(library->howMuch + 1 > library->size){
  library->size *= 2;
  library = realloc(library,sizeof(library_t)*library->size);
}

   };

void remove_record(library_t* library, int index){
  library->books[index] = library->books[library->howMuch--];
};

void display(const library_t* library){
  printf("\n\nLp.       Author             Title                 Type        Year \n");
    for(int i=0; i< library->howMuch; i++){
      printf("%d.     %s      %s      %s      %u\n",
      i+1,
    library->books[i].authorName,
    library->books[i].title,
    enumStrings[library->books[i].type],
    library->books[i].year);
    }
};

library_t* sort_by_type(const library_t* library){

library_t* sorted_library = malloc(sizeof(library_t));
sorted_library->books = malloc(sizeof(book_t)*library->howMuch);
sorted_library->howMuch = library->howMuch;
for(int i=0; i<library->howMuch; i++){
  sorted_library->books[i] = library->books[i];
}

book_t* helper = malloc(sizeof(book_t));
  for(int i=0; i<sorted_library->howMuch; i++){
    for(int j=0; j<sorted_library->howMuch-1; j++){
      if(sorted_library->books[j+1].type > sorted_library->books[j].type){
        *helper = sorted_library->books[j];
        sorted_library->books[j] = sorted_library->books[j+1];
        sorted_library->books[j+1] = *helper;
      }
    }
  }
  return sorted_library;
};

library_t* sort_by_year(const library_t* library){
  library_t* sorted_library = malloc(sizeof(library_t));
  sorted_library->books = malloc(sizeof(book_t)*library->howMuch);
  sorted_library->howMuch = library->howMuch;
  for(int i=0; i<library->howMuch; i++){
    sorted_library->books[i] = library->books[i];
  }

  book_t* helper = malloc(sizeof(book_t));
    for(int i=0; i<sorted_library->howMuch; i++){
      for(int j=0; j<sorted_library->howMuch-1; j++){
        if(sorted_library->books[j+1].year > sorted_library->books[j].year){
          *helper = sorted_library->books[j];
          sorted_library->books[j] = sorted_library->books[j+1];
          sorted_library->books[j+1] = *helper;
        }
      }
    }
    return sorted_library;
};



library_t* sort_by_title(const library_t* library){

      library_t* sorted_library = malloc(sizeof(library_t));
      sorted_library->books = malloc(sizeof(book_t)*library->howMuch);
      sorted_library->howMuch = library->howMuch;
      for(int i=0; i<library->howMuch; i++){
        sorted_library->books[i] = library->books[i];
      }


      book_t* helper = malloc(sizeof(book_t));
        for(int i=0; i<sorted_library->howMuch; i++){
          for(int j=0; j<sorted_library->howMuch-1; j++){

            printf("bool: %d\n",strcmp(library->books[j+1].title,library->books[j].title)<0);
            if((strcmp(library->books[j+1].title,library->books[j].title)<0)){
              *helper = sorted_library->books[j];
                printf("%s\n",helper->title);
              sorted_library->books[j] = sorted_library->books[j+1];
              sorted_library->books[j+1] = *helper;
            }
          }
        }

        return sorted_library;
};

library_t* sort_by_authorName(const library_t* library){
        library_t* sorted_library = malloc(sizeof(library_t));
        sorted_library->books = malloc(sizeof(book_t)*library->howMuch);
        sorted_library->howMuch = library->howMuch;
        for(int i=0; i<library->howMuch; i++){
          sorted_library->books[i] = library->books[i];
        }

        book_t* helper = malloc(sizeof(book_t));
          for(int i=0; i<sorted_library->howMuch; i++){
            for(int j=0; j<sorted_library->howMuch-1; j++){
              if(strcmp(library->books[j+1].authorName,library->books[j].authorName)<0){
                *helper = sorted_library->books[j];
                sorted_library->books[j] = sorted_library->books[j+1];
                sorted_library->books[j+1] = *helper;
              }
            }
          }
          return sorted_library;
};
library_t* find_authorName(const library_t* library,const char* authorName){
  library_t* new = new_library(library->howMuch);

  for(int i=0; i<library->howMuch; i++){
    if(strcmp(library->books[i].authorName,authorName) == 0)
      add_record(new,library->books[i].authorName,library->books[i].title,
        library->books[i].type,library->books[i].year);
  }
  return new;
};

library_t* find_type(const library_t* library, short type){
    library_t* new = new_library(library->howMuch);

    for(int i=0; i<library->howMuch; i++){
      if(library->books[i].type == type)
        add_record(new,library->books[i].authorName,library->books[i].title,
          library->books[i].type,library->books[i].year);
    }
    return new;
};
