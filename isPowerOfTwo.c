#include <stdio.h>
#include <math.h>

char *isPowerOfTwoUsingInbuiltLog(int num)
{
    double log2Value = log(num) / log(2);
    return ceil(log2Value) == floor(log2Value) ? "yes" : "no";
}

int selfLog2(int num, int r)
{
    return num > (r - 1) ? 1 + selfLog2(num/r, r) : 0;
}

int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);

    printf("\nUsing in-built log function : %s", isPowerOfTwoUsingInbuiltLog(num));

    printf("\nlog2 value of %d : %d", num, selfLog2(num, 2));     

    printf("\n\n%lf", log2(num));
    
    return 0;
}

