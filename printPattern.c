#include <stdio.h>

void printPattern(int num)
{
  if (num <= 0)
  {
    printf("%d ", num);
    return;
  }
  
  printf("%d ", num);
  printPattern(num-5);
  printf("%d ", num);
}

int main()
{
  int num;
  printf("Enter a number for pattern : ");
  scanf("%d", &num);
  
  printPattern(num);
  
  return 0;
}
