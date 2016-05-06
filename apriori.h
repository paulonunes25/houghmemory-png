#include <stdio.h>
#include <stdlib.h>

#ifndef _TIPOS_
#define _TIPOS_

typedef enum tipos{
  I,
  F,
  R,
  L,
  D,
  C,
  B,
  S
}Tipos;

typedef struct probs{
  double **msb;
  double **smsb;
  double **slsb;
  double **lsb;
}Apriori;

Apriori loadApriori(char **aprioriFiles);
#endif
