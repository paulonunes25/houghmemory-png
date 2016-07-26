#include <wset.h>

#define EDGE "****"

Wset *initSet(){
  Wset *s;
  //  printf("Init Set\n");
  s = (Wset*) malloc(sizeof(Wset));
  s->size = 0;
  s->indexed = 0;
  s->start = NULL;
  s->mark = NULL;
  s->index = NULL;
  return s;
}

Wset *insertElem(Wset *s, char *w){
  int i;
  Welem *e;
  //  printf("Insert elem\n");
  e = (Welem*) malloc(sizeof(Welem));
  e->word = (char*) malloc(5*sizeof(char));
  for(i=0; i<4; i++) e->word[i] = w[i];
  e->word[4] = '\0';
  e->next = s->start;
  s->start = e;
  s->mark = e;
  s->size++;
  if(s->indexed){
    s->indexed = 0;
    free(s->index);
    s->index = NULL;
  }
  return s;
}

int elementExistSet(Wset *s, char *w){
  //  printf("Does elem exist?\n");
  s->mark = s->start;
  while(s->mark != NULL && strncmp(s->mark->word, w, 4) != 0) s->mark = s->mark->next;
  if(s->mark == NULL) return 0;
  return 1;
}

Wset *indexSet(Wset *s){
  int i;
  if(!s->indexed){ 
    s->index = (Welem**) malloc(s->size * sizeof(Welem*));
    s->mark = s->start;
    for(i=0; i<s->size; i++){
      s->index[i] = s->mark;
      s->mark = s->mark->next;
    } 
  }
  return s;
}

void printSet(Wset *s){
  int i;
  s = indexSet(s);
  for(i=0; i<s->size; i++) printf("%s\n      ", s->index[i]->word);
}

void printGradientSpace(Wset *s){
  int x, y, z;
  s = indexSet(s);
  for(x=0; x<s->size; x++) 
    for(y=0; y<s->size; y++){
      printf("%s | %s | %s\n", EDGE, s->index[x]->word, s->index[y]->word);
      printf("%s | %s | %s\n", s->index[x]->word, s->index[y]->word, EDGE);
    for(z=0; z<s->size; z++) printf("%s | %s | %s\n", s->index[x]->word, s->index[y]->word, s->index[z]->word);
    }
}

