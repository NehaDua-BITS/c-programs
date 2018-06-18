#include <stdio.h>
#include <stdlib.h>

char *getSortedUniqueString(char *src)
{
    char *target = (char *)malloc(sizeof(src));
    int k = 0;
    int count[256] = {0};
    
    for (int i = 0; src[i] != '\0'; i++)
    {   
	int ascii = src[i]; 
	count[ascii]++;
    }
    
    for (int i = 0; i < 256; i++)
    {
	if (count[i] > 0)
	    target[k++] = i;
    }
    
    target[k] = '\0';
    
    return target;    
}

int main()
{
    char *str = "geeksforgeeks";
    
    printf("The sorted unique string is : %s", getSortedUniqueString(str));
    return 0;
}
