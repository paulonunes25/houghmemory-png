#include <rtable.h>
#include <dump.h>
#include <apriori.h>

static int *counter;

Rtable *createEntry(Rtable *r, char *gradx, int a){
  int i;
  char word[5];
  Rtable *new;
  Alist *aux;

  for(i=0; i<4; i++) word[i] = gradx[i+4];
  word[4] = '\0';

  if(r == NULL){
    counter = (int *) malloc(PAGESIZE * sizeof(int));
    for(i=0; i<PAGESIZE; i++) counter[i] = 0;
    //    printf("First entry\n");
    new = (Rtable*) malloc(sizeof(Rtable));
    new->grad = (char*) malloc(13*sizeof(char));
    for(i=0; i<13; i++) new->grad[i] = gradx[i];
    new->list = (Alist*) malloc(sizeof(Alist));
    new->list->a = 4 * a;
    new->list->next = NULL;
    new->next = NULL;
  } else {
    //    printf("New entry\n");
    new = r;
    while(r->next != NULL && strcmp(r->grad, gradx)!= 0) r = r->next;
    if(strcmp(r->grad, gradx)== 0){
      //      printf("existing Grad\n");
      aux = (Alist*) malloc(sizeof(Alist));
      aux->a = 4 * a;
      aux->next = r->list;
      r->list = aux;
    } else {
      //      printf("New Grad\n");
      r->next = (Rtable*) malloc(sizeof(Rtable));
      r = r->next;
      r->grad = (char*) malloc(13*sizeof(char));
      for(i=0; i<13; i++) r->grad[i] = gradx[i];
      r->list = (Alist*) malloc(sizeof(Alist));
      r->list->a = 4 * a;
      r->list->next = NULL;
      r->next = NULL;
    }

  }
  return new;
}

void printShape(Rtable *shape){
  Alist *aux;
  while(shape != NULL){
    printf("Rtable entry: Grad = %s ", shape->grad);
    aux = shape->list;
    while(aux != NULL){
      printf("| subentry: A = %d\n                                  ", aux->a);
      aux = aux->next;
    }
    printf("\n");
    shape = shape->next;
  }
}

void printTable(double *accTbl){
  int i;
  for(i=0; i<PAGESIZE; i++)
    printf("Position = %04d, Accumulator = %le, Counter = %d\n",i, accTbl[i], counter[i]);
}

void exportTable(char *filename, double *accTbl){
  int i;
  FILE *tableout;

  tableout = fopen(filename,"w");

  for(i=0; i<PAGESIZE; i++)
    fprintf(tableout, "%d;%d\n", i, counter[i]);
  fclose(tableout);
}


double wordsizeProb(Dump dump, int x, Rtable *shape, int y, Apriori p){
  int i;
  double increment = 1.0;

  if(x >= 0 && x+3 < PAGESIZE) {
    if(shape->grad[y]=='C'){
      for(i=0; i<4; i++){
//	printf("Value = %d, Index = %d, Type = %c, Prob = %le\n", dump[x+i], typeIndex(shape->grad[y+i]), shape->grad[y+i], p.bigw[i][dump[x+i]][typeIndex(shape->grad[y+i])]);

	increment *= p.bigw[i][dump[x+i]][typeIndex(shape->grad[y+i])];
      } 
    } else {
     for(i=0; i<4; i++){
//	printf("Value = %d, Index = %d, Type = %c, Prob = %le\n", dump[x+i], typeIndex(shape->grad[y+i]), shape->grad[y+i], p.littlew[i][dump[x+i]][typeIndex(shape->grad[y+i])]);

	increment *= p.littlew[i][dump[x+i]][typeIndex(shape->grad[y+i])];
      }
    }
  } else {
 //   printf("byte out of PAGESIZE, increment set to 1.0\n");
  }
  return increment;
}

void zeroAccumulator(){
  int i;
  for(i=0; i<PAGESIZE; i++) counter[i] = 0;
}

void incrementAccumulator(Dump dump, int x, Rtable *shape, Apriori p, double *AccumulatorTable){
  int i, j, k;
  double increment;
  Alist *aux;
//  printf("\n***************************\n*****  New increment  *****\n***************************\n");

  while(shape != NULL){
    if((x-4>=0 || shape->grad[0]=='Z')&&(x+8<PAGESIZE || shape->grad[8]=='Z')){
      increment = 1.0;
/*      printf("Offset = %d\nDump = ",x);
      for(i=-4;i<8;i++) 
	if(x+i >= 0 && x+i < PAGESIZE) 
	  printf("%d, ",dump[x+i]);
      printf("\n\n");
*/
      increment *= wordsizeProb(dump, x-4, shape, 0, p);
      increment *= wordsizeProb(dump, x, shape, 4, p);
      increment *= wordsizeProb(dump, x+4, shape, 8, p);

      aux = shape->list;
      while(aux != NULL){
//	printf("| Entry: Grad = %s, subentry: A = %d, increment = %le\n", shape->grad, aux->a, increment);
	if(x + aux->a >= 0){
	  if(increment > 0.0) counter[x + aux->a]++; 
	  AccumulatorTable[x + aux->a] *= increment;
	}
	aux = aux->next;
      }
 //     printf("\n");
    }
    shape = shape->next;
  }
}
