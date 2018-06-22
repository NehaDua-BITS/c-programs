#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findPatterns(char *str)
{
  if (!str || strlen(str) < 3)
    return 0;

  int count = 0;
  char last = str[0];
  for (int i = 1; i < strlen(str); i++)
  {
    if (str[i]=='0' && last == '1')
    {      
      char *pattern = calloc(strlen(str), sizeof(char));
      int k = 0;
      pattern[k++] = '1';	
      while (i < strlen(str) && str[i]=='0')
      {
        pattern[k++] = '0';
	i++;
      }
      
      if (i >= strlen(str)) break;  //reached end of string
      
      if (str[i]=='1')
      {
	pattern[k++] = '1';
	printf("\niindex = %lu %s", i - strlen(pattern) + 1, pattern);
	free(pattern);
	count++;
      }
    }
    
    last = str[i];
  }
  
  return count;
}

int main()
{
  char *str = "1001010001001001";
  int count = findPatterns(str);               //regex : 1(0+)1
  printf("\nNo. of patterns are : %d", count);

  return 0;
}

