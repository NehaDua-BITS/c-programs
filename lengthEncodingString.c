#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getRunLengthEncoding(char *str)
{
    int count = 0;
    char *encodedString = (char *)calloc(strlen(str), sizeof(char));    
    char currentChar = '\0';
    int j = 0;
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (currentChar == '\0')
        {
            encodedString[j++] = str[i];
            currentChar = str[i];
            count++;
        }
        else 
        {
            if(currentChar == str[i])
            {
                count++;
            }
            else
            {
                encodedString[j++] = '0' + count;
                encodedString[j++] = str[i];
                count = 1;
                currentChar = str[i];
            }
        }            
    }
    
    if (count > 0)
        encodedString[j] = '0' + count;
    
    return encodedString;
}

int main()
{
    char *str = "wkwwwaaadexxbbbbbj";
    printf("Run length encoding of string is : %s", getRunLengthEncoding(str));    
    
    return 0;
}
