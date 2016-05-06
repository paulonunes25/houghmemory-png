#include <apriori.h>

Apriori loadApriori(char **aprioriFiles){
  int i, n;
  FILE *input;
  Apriori p;

  p.msb = (double **) malloc(256 * sizeof(double *));
  p.smsb = (double **) malloc(256 * sizeof(double *));
  p.slsb = (double **) malloc(256 * sizeof(double *));
  p.lsb = (double **) malloc(256 * sizeof(double *));

  //    printf("Reading a priori\n");
  input = fopen(aprioriFiles[0],"r");
  //    printf("file opened\n");
  for(i=0; i<256; i++){ 
    p.msb[i] = (double *) malloc(9 * sizeof(double));
    fscanf(input,"%d; %le; %le; %le; %le; %le; %le; %le; %le; %le;\n",&n, &p.msb[i][0], &p.msb[i][1], &p.msb[i][2], &p.msb[i][3], &p.msb[i][4], &p.msb[i][5], &p.msb[i][6], &p.msb[i][7], &p.msb[i][8]);
  }
  //    printf("file closed\n");
  fclose(input);

  //    printf("Byte 1 finished\n");
  input = fopen(aprioriFiles[1],"r");
  for(i=0; i<256; i++){ 
    p.smsb[i] = (double *) malloc(9 * sizeof(double));
    fscanf(input,"%d; %le; %le; %le; %le; %le; %le; %le; %le; %le;\n",&n, &p.smsb[i][0], &p.smsb[i][1], &p.smsb[i][2], &p.smsb[i][3], &p.smsb[i][4], &p.smsb[i][5], &p.smsb[i][6], &p.smsb[i][7], &p.smsb[i][8]);
  }
  fclose(input);
  //    printf("Byte 2 finished\n");
  input = fopen(aprioriFiles[2],"r");
  for(i=0; i<256; i++){ 
    p.slsb[i] = (double *) malloc(9 * sizeof(double));
    fscanf(input,"%d; %le; %le; %le; %le; %le; %le; %le; %le; %le;\n",&n, &p.slsb[i][0], &p.slsb[i][1], &p.slsb[i][2], &p.slsb[i][3], &p.slsb[i][4], &p.slsb[i][5], &p.slsb[i][6], &p.slsb[i][7], &p.slsb[i][8]);
  }
  fclose(input);
  //    printf("Byte 3 finished\n");
  input = fopen(aprioriFiles[3],"r");
  for(i=0; i<256; i++){ 
    p.lsb[i] = (double *) malloc(9 * sizeof(double));
    fscanf(input,"%d; %le; %le; %le; %le; %le; %le; %le; %le; %le;\n",&n, &p.lsb[i][0], &p.lsb[i][1], &p.lsb[i][2], &p.lsb[i][3], &p.lsb[i][4], &p.lsb[i][5], &p.lsb[i][6], &p.lsb[i][7], &p.lsb[i][8]);
  }
  fclose(input);
  //    printf("Byte 4 finished\n");
  return p;
}
