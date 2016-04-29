#include <rtable.h>

double prob1[256][9];
double prob2[256][9];
double prob3[256][9];
double prob4[256][9];

int main(int argc, char *argv[]){
  int i, c, x, p, q, r, n;
  FILE* input; 
  char any[4] = {'*', '*', '*', '*'};
  char grad[13];
  char *buf;
  Rtable *shape = NULL;

  if(argc!=6) return 1;

  buf = (char*) malloc(5 * sizeof(char));
  for(i=0; i<4; i++) grad[i] = any[i];
  for(i=4; i<8; i++) grad[i] = any[i-4];
  for(i=8; i<12; i++) grad[i] = any[i-8];
  grad[12] = '\0';

  input = fopen(argv[1],"r");
  for(i=0; i<256; i++){ 
    fscanf(input,"%d; %le; %le; %le; %le; %le; %le; %le; %le; %le;\n",&n, &prob1[i][0], &prob1[i][1], &prob1[i][2], &prob1[i][3], &prob1[i][4], &prob1[i][5], &prob1[i][6], &prob1[i][7], &prob1[i][8]);
  }

  input = fopen(argv[2],"r");
  for(i=0; i<256; i++){ 
    fscanf(input,"%d; %le; %le; %le; %le; %le; %le; %le; %le; %le;\n",&n, &prob2[i][0], &prob2[i][1], &prob2[i][2], &prob2[i][3], &prob2[i][4], &prob2[i][5], &prob2[i][6], &prob2[i][7], &prob2[i][8]);
  }

  input = fopen(argv[3],"r");
  for(i=0; i<256; i++){ 
    fscanf(input,"%d; %le; %le; %le; %le; %le; %le; %le; %le; %le;\n",&n, &prob3[i][0], &prob3[i][1], &prob3[i][2], &prob3[i][3], &prob3[i][4], &prob3[i][5], &prob3[i][6], &prob3[i][7], &prob3[i][8]);
  }

  input = fopen(argv[4],"r");
  for(i=0; i<256; i++){ 
    fscanf(input,"%d; %le; %le; %le; %le; %le; %le; %le; %le; %le;\n",&n, &prob4[i][0], &prob4[i][1], &prob4[i][2], &prob4[i][3], &prob4[i][4], &prob4[i][5], &prob4[i][6], &prob4[i][7], &prob4[i][8]);
  }

  input = fopen(argv[5],"r");

  fscanf(input,"%s\n",buf);
  for(i=4; i<8; i++) grad[i] = buf[i-4];
  x=0;

  while(fscanf(input,"%s\n",buf)>0){
    for(i=8; i<12; i++) grad[i] = buf[i-8];

    //    printf("createEntry: Grad = %s, x = %d\n", grad, x);
    shape = createEntry(shape, grad, x--);

    for(i=0; i<8; i++) grad[i] = grad[i+4];
  }
  for(i=8; i<12; i++) grad[i] = any[i-8];
  //  printf("createEntry: Grad = %s, x = %d\n", grad, x);
  shape = createEntry(shape, grad, x--);

  //  printf("\n*****\n\n");

  printShape(shape);

  return 0;
}
