#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _atoi(char *str)
{
    int num = 0;
    
    if (!str || strcmp(str,"") == 0)
    {
	printf("Error: Null/empty string");
	exit(0);
    }
    
    for (int i = 0; str[i] != '\0'; i++)
    {
	if (str[i] < '0' || str[i] > '9')
	{
	    printf("Error: Invalid characters in string");
	    exit(0);
	}
	
	num = num * 10 + str[i] - '0';  
    }
    
    return num;
}

int main()
{
    char str[] = "0823";
    printf("Corresponding number is = %d", _atoi(str));
    
    return 0;
}
