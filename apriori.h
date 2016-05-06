#include <stdio.h>
#include <stdlib.h>
#include <byteType.h>

typedef struct probs{
  double **msb;
  double **smsb;
  double **slsb;
  double **lsb;
}Apriori;

Apriori loadApriori(char **aprioriFiles);

