#include <stdio.h>
#include <stdlib.h>
#include <byteType.h>
#ifndef _APRIORI_
#define _APRIORI_

typedef struct probs{
  double **msb;
  double **smsb;
  double **slsb;
  double **lsb;
  double ***littlew;
  double ***bigw;
  double ***littlehw;
}Apriori;

Apriori loadApriori(char **aprioriFiles);

#endif
