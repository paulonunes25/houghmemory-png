#include <rtable.h>

int main(int argc, char *argv[]){
  int i, c, x, p, q, r;
  FILE* input; 
  char any[4] = {'*', '*', '*', '*'};
  char grad[13];
  char *buf;
  Rtable *shape = NULL;

  if(argc!=2) return 1;

  buf = (char*) malloc(5 * sizeof(char));
  for(i=0; i<4; i++) grad[i] = any[i];
  for(i=4; i<8; i++) grad[i] = any[i-4];
  for(i=8; i<12; i++) grad[i] = any[i-8];
  grad[12] = '\0';

  input = fopen(argv[1],"r");

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
