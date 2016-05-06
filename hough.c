#include <rtable.h>
#include <dump.h>
#include <apriori.h>

#define CONFIGFILE "hough.config"

char **readConfig(char *filename){
  FILE *config;
  char *input1 = NULL, *input2 = NULL, *input3 = NULL, *input4 = NULL, *label, *value, **inputs;

  label = (char*) malloc(20*sizeof(char));
  value = (char*) malloc(20*sizeof(char));

  config = fopen("hough.config","r");

  while(fscanf(config,"%s = %s\n",label,value)>0){
    //    printf("Label: %s, Value: %s\n",label,value);
    if(strcmp("priori_byte1",label)==0){
      input1 = (char*) malloc(strlen(label)*sizeof(char));
      strcpy(input1,value);
    }
    if(strcmp("priori_byte2",label)==0){
      input2 = (char*) malloc(strlen(label)*sizeof(char));
      strcpy(input2,value);
    }
    if(strcmp("priori_byte3",label)==0){
      input3 = (char*) malloc(strlen(label)*sizeof(char));
      strcpy(input3,value);
    }
    if(strcmp("priori_byte4",label)==0){
      input4 = (char*) malloc(strlen(label)*sizeof(char));
      strcpy(input4,value);
    }
  }

  free(label);
  free(value);

  if(input1!=NULL && input2!=NULL && input3!=NULL && input4!=NULL){
    inputs = (char **) malloc(4 * sizeof(char *));
    inputs[0] = input1;
    inputs[1] = input2;
    inputs[2] = input3;
    inputs[3] = input4;
    return inputs;
  }
  return NULL;
}

Rtable *loadShape(char *filename){
 int i, x;
  char any[4] = {'*', '*', '*', '*'};
  char grad[13];
  char *buf;
  Rtable *shape = NULL;
  FILE* input; 

  buf = (char*) malloc(5 * sizeof(char));
  for(i=0; i<4; i++) grad[i] = any[i];
  for(i=4; i<8; i++) grad[i] = any[i-4];
  for(i=8; i<12; i++) grad[i] = any[i-8];
  grad[12] = '\0';

  input = fopen(filename,"r");

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
  fclose(input);
  //  printf("\n*****\n\n");
  return shape;
}

void parse(dump, shape){

}

int main(int argc, char *argv[]){
  FILE* input, config; 
  Rtable *shape = NULL;
  Dump dump;
  char **aprioriFiles;
  Apriori p;

  if(argc!=2){
    printf("Commandline parameter error\n");
    return 1;
  }

  aprioriFiles = readConfig(CONFIGFILE);
  if(aprioriFiles == NULL){
    printf("Config file error\n");
    return 1;
  }

  p = loadApriori(aprioriFiles);

  shape = loadShape(argv[1]);

  printShape(shape);

  dump = loadDump(NULL);

  printDump(dump);

  parse(dump, shape);

  return 0;
}
