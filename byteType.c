#include <byteType.h>

static const char typeChar[NTYPES] = {'I', 'F', 'R', 'L', 'D', 'C', 'B', 'S', 'P', 'Z'};
static const char *typeStr[NTYPES] = {"Int", "Float", "References", "Long", "Double", "Char", "Byte", "Short", "Padding", "Any"};

ByteTypes typeIndex(char x){
  switch(x) {
  case 'I':
    return I;
    break; 
  case 'F':
    return F;
    break; 
  case 'R':
    return R;
    break; 
  case 'L':
    return L;
    break; 
  case 'D':
    return D;
    break; 
  case 'C':
    return C;
    break;
  case 'B':
    return B;
    break;
  case 'S':
    return S;
    break;
  case 'P':
    return P;
    break;
  case 'Z':
    return Z;
    break;
  }
}
