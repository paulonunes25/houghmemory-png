#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <byteType.h>

#define PAGESIZE 1024
#define Dump unsigned char* 

Dump addNoise(Dump x, int i);

int printDump(Dump x);

Dump loadDump(char *filename);
