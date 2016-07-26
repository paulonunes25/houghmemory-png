#include <apriori.h>

Apriori loadApriori(char **aprioriFiles){
  int i, j, n;
  FILE *input;
  Apriori p;
  double **aux[4];
  aux[0] = p.msb = (double **) malloc(256 * sizeof(double *));
  aux[1] = p.smsb = (double **) malloc(256 * sizeof(double *));
  aux[2] = p.slsb = (double **) malloc(256 * sizeof(double *));
  aux[3] = p.lsb = (double **) malloc(256 * sizeof(double *));
  p.littlew = (double ***) malloc(4 * sizeof(double **));
  p.bigw = (double ***) malloc(4 * sizeof(double **));
  p.littlehw = (double ***) malloc(4 * sizeof(double **));

  p.littlehw[2] = p.bigw[3] = p.littlew[0] = p.lsb;
  p.littlehw[3] = p.bigw[2] = p.littlew[1] = p.slsb;
  p.littlehw[0] = p.bigw[1] = p.littlew[2] = p.smsb;
  p.littlehw[1] = p.bigw[0] = p.littlew[3] = p.msb;

  //    printf("Reading a priori\n");

  for(j=0; j<4; j++){

    input = fopen(aprioriFiles[j],"r");
    //        printf("file opened\n");
    for(i=0; i<256; i++){ 
      aux[j][i] = (double *) malloc(NTYPES * sizeof(double));
      fscanf(input,"%d; %le; %le; %le; %le; %le; %le; %le; %le; %le;\n",&n, &aux[j][i][typeIndex('D')], &aux[j][i][typeIndex('F')], &aux[j][i][typeIndex('I')], &aux[j][i][typeIndex('L')], &aux[j][i][typeIndex('R')], &aux[j][i][typeIndex('S')], &aux[j][i][typeIndex('B')], &aux[j][i][typeIndex('C')], &aux[j][i][typeIndex('P')]);
      aux[j][i][typeIndex('Z')] = 1.0;
    }
    //        printf("file closed\n");
    fclose(input);

  }
  return p;
}
