#include <stdio.h>
#include <string.h>

#define MAX 50

void removeTrailingSpaces(char *str)
{
    int length = strlen(str);
    printf("Total length of string = %d\n", length);
    
    //remove trailing spaces
    int i;
    for (i = strlen(str) - 1 ; i >= 0 && str[i] == ' '; i--);
    
    if (str[i+1] == ' ')
        str[i+1] = '\0';

    length = strlen(str);
    printf("New length of string = %d\n", length);    

    int spaces = 0;
    char *index = str;
    while ((index = strchr(index, ' ')) != NULL)
    {
        spaces++;
        index++;
    }    
    
    printf("no. of spaces = %d\n", spaces);
    printf("Actual length of string : %d\n", length - spaces);
    printf("New length of the string : %d\n", length + spaces*2);
    
    int newLength = length + 2*spaces;
    str[newLength] = '\0';
    
    for (int i = newLength - 1, j = length - 1; i >= 0; j--)
    {
        if (str[j] == ' ')
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
        else
        {
            str[i] = str[j];
            i--;
        }
    }
    
    printf("Urlized string = %s\n", str);
}

void urlization(char *str)
{
    //sanitize string
    removeTrailingSpaces(str);
    
    //char *token = strtok(str, " ");
            
}

int main()
{
    char string[MAX] = "my  string  with spaces";
    urlization(string);
    return 0;
}
