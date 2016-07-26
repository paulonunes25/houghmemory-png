//#include <wset.h>
#ifndef _RTABLE_
#define _RTABLE_

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

void printTable(double *accTbl);

void exportTable(char *filename, double *accTbl);

void zeroAccumulator();

//void incrementAccumulator(Dump dump, int x, Rtable *shape, Apriori p, double *AccumulatorTable);

#endif
