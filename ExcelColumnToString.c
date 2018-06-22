#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strrev(char *str)
{
    char temp;
    for(int i = 0, j = strlen(str) - 1; i < j;  i++, j--)
    {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
    }
}

char *convertNumToName(int n)
{
  char *colName= calloc(10, sizeof(*colName));
  int k = 0;
  int rem;
  while (n)
  {
    rem = n % 26;
    n = n /26;
    
    if (!rem)
    {
      colName[k++] = 'Z';
      n--;
    }
    else
    {
      colName[k++] = 'A' + rem - 1;
    }
  }

  strrev(colName);
  
  return colName;
}

int getColNumFromName(char *name)
{
  int n = 0;
  
  for (int i = 0; i < strlen(name); i++)
  {
    n = n * 26 + (name[i] - 'A' + 1);
  } 
  
  return n;
}
 
int main()
{
  int num;
  printf("Enter column no. : ");
  scanf("%d", &num);
  
  char *name = convertNumToName(num);
  printf("The corresponding column name : %s", name);
  
  int n = getColNumFromName(name);
  printf("\nThe corresponding column num : %d", n);
  
  return 0;
}
