#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPowerOfTwo(int num)
{
    return num && !(num & (num - 1));
}

int findSetBit(int num)
{
    if (!isPowerOfTwo(num))
    {
        printf("Error: Invalid number. Not power of 2");
        exit(0);
    }
    
    int pos = 0;
    while(num)
    {
        num >>= 1;
        pos++;
    }
    
    return pos;
}

int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    
    printf("\nThe only set bit is at position : %d", findSetBit(num));
    return 0;
}
