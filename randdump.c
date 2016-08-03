#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <byteType.h>

#define PAGESIZE 1024
#define Dump unsigned char*

void main(int argc, char *argv[]){
  int i, step, di, dist=250;
  float df;
  void *dr;
  long dl;
  double dd;
  char dc;
  unsigned char db;
  short ds;
  Dump x;
  ByteTypes t;
  FILE *dumpfile;

  x = (Dump) malloc((PAGESIZE+15) * sizeof(unsigned char));
  if(argc==2) dist = atoi(argv[1]);

    srand(time(NULL));
    step = 4;
    i=0;
    while(i < PAGESIZE){
      t = rand()%8;
      if(i >= step) t = 8;
      switch(t) {
      case I:
	di = rand()%200 - 100;
	memcpy(&x[i], &di, 4);
	i+=4;
	break; 
      case F:
	df = (float)((float)(rand()%1000))/((float)(rand()%30));
	memcpy(&x[i], &df, 4);
	i+=4;
	break; 
      case R:
	dr = malloc(sizeof(int));
	memcpy(&x[i], &dr, 4);
	i+=4;
	free(dr);
	break; 
      case L:
	dl = (long) rand();
	memcpy(&x[i], &dl, 4);
	i+=4;
	break; 
      case D:
	dd = (double)((double)(rand()%1000))/((double)(rand()%30));
	memcpy(&x[i], &dd, 4);
	i+=4;
	break; 
      case C:
	dc = ' ' + (rand()%95);
	memcpy(&x[i], &dc, 1);
	i+=1;
	dc = ' ' + (rand()%95);
	memcpy(&x[i], &dc, 1);
	i+=1;
	dc = ' ' + (rand()%95);
	memcpy(&x[i], &dc, 1);
	i+=1;
	dc = ' ' + (rand()%95);
	memcpy(&x[i], &dc, 1);
	i+=1;
	break;
      case B:
	db = rand()%256;
	memcpy(&x[i], &db, 1);
	i+=1;
	db = rand()%256;
	memcpy(&x[i], &db, 1);
	i+=1;
	db = rand()%256;
	memcpy(&x[i], &db, 1);
	i+=1;
	db = rand()%256;
	memcpy(&x[i], &db, 1);
	i+=1;
	break;
      case S:
	ds = rand()%65536 - 32768;
	memcpy(&x[i], &ds, 2);
	i+=2;
	ds = rand()%65536 - 32768;
	memcpy(&x[i], &ds, 2);
	i+=2;
	break;
      case 8:
	di = 25;
	memcpy(&x[i], &di, 4);
	i+=4;
	df = 3.14159;
	memcpy(&x[i], &df, 4);
	i+=4;
	dc = 'U';
	memcpy(&x[i], &dc, 1);
	i+=1;
	dc = 'C';
	memcpy(&x[i], &dc, 1);
	i+=1;
	dc = 'D';
	memcpy(&x[i], &dc, 1);
	i+=1;
	dc = '\0';
	memcpy(&x[i], &dc, 1);
	i+=1;
	x[i++] = 104;
	x[i++] = 75;
	x[i++] = 105;
	x[i++] = 65;
	step = i + (rand()%dist);
	break;
      }
    }
    dumpfile = fopen("dump.tmp","wb");
    if(dumpfile != NULL) fwrite(x, sizeof(unsigned char), PAGESIZE, dumpfile); 
  fclose(dumpfile);
}

