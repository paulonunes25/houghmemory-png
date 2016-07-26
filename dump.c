#include <dump.h>

const char *int_to_binary(int x)
{
    static char b[33];
    b[0] = '\0';

    unsigned int z;
    for (z = (1 << 31); z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

Dump addNoise(Dump x, int i){
  int j, k, p;
  unsigned int mask;
  FILE *noise;
  char filename[20];
  unsigned char b1, b2, b3, b4;

  if(i==0) return x;
  sprintf(filename, "random%02d.txt", i);
  noise = fopen(filename, "r");
  for(j=0; j<PAGESIZE; j+=4){
    mask = 0;
    for(k=0; k<i; k++){
      fscanf(noise, "%d\n", &p);
      mask = mask | (1<<p);
    }
    b1 = (unsigned char) (mask >> 24);
    b2 = (unsigned char) (mask >> 16);
    b3 = (unsigned char) (mask >> 8);
    b4 = (unsigned char) (mask);
 
    x[j] ^= b1; 
    x[j+1] ^= b2;
    x[j+2] ^= b3;
    x[j+3] ^= b4;

  }
  fclose(noise); 
  return x;
}

int printDump(Dump x){
  int i;
  printf("Dump = 0x");
  for(i=0; i<PAGESIZE; i++) printf("%02x", x[i]);
  printf("\n");
  return 1;
}

Dump loadDump(char *filename){
  int i, step, di;
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

  if(filename == NULL){

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
	step = i + 25 + (rand()%10);
	break;
      }
    }
    dumpfile = fopen("dump.tmp","wb");
    if(dumpfile != NULL) fwrite(x, sizeof(unsigned char), PAGESIZE, dumpfile); 
  }else{
    dumpfile = fopen(filename,"rb");
    fread(x, sizeof(unsigned char), PAGESIZE, dumpfile);
  }
  fclose(dumpfile);
  return x;
}

