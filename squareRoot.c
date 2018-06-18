#include <stdio.h>

int squareRoot(int num)
{
    if (num == 0 || num == 1)
        return num;
    
    int i;
    for (i = 1; i * i <= num; i++);

    return i-1;
}

int squareRootUsingBinarySearch(int num)
{
    int l = 0;
    int r = num;
    int root = -1;
    
    while(l <= r)
    {
        int mid = (l + r) / 2;
        int result = mid * mid;
        if (result == num)
        {
            root = mid;
            break;
        }
        else if (result > num)
        {
            r = mid - 1;
        }    
        else
        {
            l = mid + 1;
        }
    }
    
    return root != -1 ? root : r;
}

int main()
{
    int num;
    printf("Enter number : ");
    scanf("%d", &num);
    
    printf("Square Root of %d = %d\n", num, squareRoot(num));

    printf("Square Root using Binary Search of %d = %d\n", num, squareRootUsingBinarySearch(num));
    
    return 0;
}

