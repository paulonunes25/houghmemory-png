#include <stdio.h>
#include <stdlib.h>
#ifndef _TIPOS_
#define _TIPOS_

typedef enum tipos{
  I,
  F,
  R,
  L,
  D,
  C,
  B,
  S,
  P
}ByteTypes;

static const char typeChar[9];
static const char *typeStr[9];

#endif


