#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _WSET__
#define _WSET_


typedef struct Welem{
  char *word;
  struct Welem *next;
}Welem;

typedef struct Wset{
  int size;
  int indexed;
  Welem *start;
  Welem *mark;
  Welem **index;
}Wset;

Wset *initSet();

Wset *insertElem(Wset *s, char *w);

int elementExistSet(Wset *s, char *w);

Wset *indexSet(Wset *s);

void printSet(Wset *s);

void printGradientSpace(Wset *s);

#endif
