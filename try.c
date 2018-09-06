#include <stdio.h>
#include <stdlib.h>

int main()
{
  //allocating int aray
  int *ptr = malloc(sizeof *ptr * 8);
  ptr[0] = 1;
  printf("ptr :  %d", *ptr);
  
  return 0;
}
