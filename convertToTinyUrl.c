#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getTinyUrl(int id)
{
  char map[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
  
  //convert id to base 62
  int index = -1;
  char *result = calloc(7, sizeof *result);
  int k = 0;
  while (id)
  {
    index = id % 62;
    result[k++] = map[index];
    id  = id / 62;
  }
  
  return result;  
}

int getAbsolutePositionInMap(char ch)
{
  int relativePosition = -1;
  int numOfElementsBefore = 0;
  
  if (ch >= 'a' && ch<='z')
  {
    relativePosition = ch - 'a';
  }
  else if (ch >= 'A' && ch<='Z')
  {
    relativePosition = ch - 'A';
    numOfElementsBefore = 26;    
  }
  else if (ch >='0' && ch <= '9')
  {
    relativePosition = ch - '0';
    numOfElementsBefore = 52;    
  }
  
  return relativePosition + numOfElementsBefore;
}

int getDatabaseId(char *shortUrl)
{
  int id = 0;
  for (int i = strlen(shortUrl)-1; i >= 0; i--)
  {
    id = id * 62 + getAbsolutePositionInMap(shortUrl[i]);
  }
  
  return id;
}

int main()
{
  int databaseId = 12345;   //long urls are stored in database with particular id
  
  char *shortUrl = getTinyUrl(databaseId);
  printf("Generated short url : %s", shortUrl);
  
  printf("\nDatabase id from short url : %d", getDatabaseId(shortUrl));
  
  return 0;
}
