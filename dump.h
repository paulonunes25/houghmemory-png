#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <apriori.h>

#define PAGESIZE 4096
#define Dump unsigned char* 

int printDump(Dump x);

Dump loadDump(char *filename);