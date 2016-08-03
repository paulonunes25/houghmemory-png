#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  int i;
  unsigned char *x;
  FILE *dumpfile;

  x = (unsigned char *) malloc((1024) * sizeof(unsigned char));

  dumpfile = fopen(argv[1],"rb");
  fread(x, sizeof(unsigned char), 1024, dumpfile);

  for(i=0; i<1020; i++)
    if(x[i]=='U' && x[i+1]=='C' && x[i+2]=='D')
      printf("position=%d\n", i-8);

  fclose(dumpfile);
}

