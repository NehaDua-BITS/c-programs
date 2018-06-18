#include <stdio.h>

#define MAX 1000

void multiply(int *result, int *size, int num)
{
  int carry = 0;
  int product;
  for (int i = 0; i < *size; i++)
  {
    product = result[i] * num + carry;
    result[i] = product % 10;
    carry = product / 10;
  }
  
  while(carry)
  {
    result[(*size)++] = carry % 10;
    carry = carry / 10;
  }
}

void printFactorial(int num)
{
  int factorialResult[MAX] = {0};
  int resultSize = 0;
  
  //initializing first digit
  factorialResult[0] = 1;
  resultSize = 1;
  
  //multiply remaining numbers
  for (int i = 2; i <= num; i++)
  {
    multiply(factorialResult, &resultSize, i);
  }

  for (int i = resultSize-1; i >=0; i--)
    printf("%d", factorialResult[i]);
}

int main()
{
  int num;
  printf("Enter a number for factorial : ");
  scanf("%d", &num);
  
  printf("\nFactorial of %d is : ", num);
  printFactorial(num);
  
  return 0;
}
