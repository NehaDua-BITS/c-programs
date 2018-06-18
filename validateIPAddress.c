#include <stdio.h>
#include <string.h>

#define MAX 16

int isValidNumber(char *str)
{
    if (!str || (strlen(str) > 3) || !strlen(str))
	return 0;
	
    for (int i = 0; str[i] != '\0'; i++)
    {
	if (str[i] < '0' || str[i] > '9')
	    return 0;
    }

    int num;
    sscanf(str, "%d", &num);
    
    if (num < 0 || num > 255)
      return 0;
    
    return 1;
}

int isIPAddressValid(char *ipAddress)
{
    if (!ipAddress ||  !strlen(ipAddress))
    {
	printf("\nIP address is null/empty");
	return 0;
    }
    
    char *token = strtok(ipAddress, "."); 
    int count = 0;
    
    while(token)
    {
	if (!isValidNumber(token))
	{
	    printf("\nInvalid Number in ip address found : %s", token);
	    return 0;
	}
	count++;
	token = strtok(NULL, ".");
    }
    
    return count == 4;
}

int main()
{
    char ipAddress[MAX] = {0};
    printf("Enter a IP address : ");
    scanf("%s", ipAddress);
    
    printf("\nEntered address : %s", ipAddress);
    
    printf("\nIs IP address valid : %s", isIPAddressValid(ipAddress) ? "yes" : "no"); 
    return 0;
}
