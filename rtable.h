#include <wset.h>

typedef struct Alist{
  int a;
  struct Alist *next;
}Alist;

typedef struct Rtable{
  char *grad;
  Alist *list;
  struct Rtable *next;
}Rtable;

Rtable *createEntry(Rtable *r, char *gradx, int a);

void printShape(Rtable *shape);
