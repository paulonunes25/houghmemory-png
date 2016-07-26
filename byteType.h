#include <stdio.h>
#include <stdlib.h>
#ifndef _TIPOS_
#define _TIPOS_

#define NTYPES 10

typedef enum tipos{
  I,
  F,
  R,
  L,
  D,
  C,
  B,
  S,
  P,
  Z
}ByteTypes;

static const char typeChar[NTYPES];
static const char *typeStr[NTYPES];

ByteTypes typeIndex(char x);

#endif


