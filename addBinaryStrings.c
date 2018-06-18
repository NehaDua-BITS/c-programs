#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 32

char *sumOfBinary(char *str1, char *str2)
{
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    int max = length1 > length2 ? length1 : length2;
    char *result = (char *)calloc(max + 2, sizeof(char));
    int k = max;
    int carry = 0;
    for (int i = length1 - 1, j = length2 - 1; i >=0 || j>=0; i--, j--)
    {
	int sum = ( i >=0 ? (str1[i] - '0') : 0) + ( j>=0 ? (str2[j] - '0') : 0) + carry;
	if (sum == 2)
	{
	    carry = 1;
	    result[k--] = '0';
	}
	else
	{
	    carry = 0;
	    result[k--] = '0' + sum; 
	}
    }
    
    if (k == 0)
	result[k] = '0' + carry;
	
    return result;
}

int main()
{
    char str1[MAX];
    char str2[MAX];
    
    printf("Enter binary string 1 : ");
    scanf("%s", str1);
    printf("\nEnter binary string 2 : ");
    scanf("%s", str2);
    
    printf("\nSum of %s and %s = %s", str1, str2, sumOfBinary(str1, str2));
    return 0;
}
