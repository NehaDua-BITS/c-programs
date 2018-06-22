#include <stdio.h>

int main()
{
  unsigned char ch = 100;
  
  ch = ((ch & 0x0f) << 4) | ((ch & 0xf0) >> 4);
  printf("ch is %d", '9');
  
  return 0;
}
