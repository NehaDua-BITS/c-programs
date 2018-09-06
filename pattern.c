#include <stdio.h>
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   for (int i = 0; i < 5; i++)
    {
        char ch = ' ';
        for (int j = 0; j < 9-i; j++)
        {
           if (j == i)
           {
               ch = '*';
           }
            printf("%c", ch);
        }
        printf("\n");
    }
    
    return 0;
}
