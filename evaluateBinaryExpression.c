#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char evaluate(char *origExpr)
{    
    int length = strlen(origExpr);
    char expr[length];
    int i;
    
    strcpy(expr, origExpr);
    
    for (i = 1; i < length; i+=2)
    {
      switch(expr[i])
      {
        case 'A':
          expr[i+1] = (expr[i-1] == '0' || expr[i+1] == '0') ? '0' : '1';
          break;
          
        case 'B':
          expr[i+1] = (expr[i-1] == '1' || expr[i+1] == '1') ? '1' : '0';  
          break;
        
        case 'C':
          expr[i+1] = (expr[i-1] == expr[i+1]) ? '0' : '1';  
          break;
        
        default: 
          printf("Invalid expression");
          exit(0);
      }
    }
    
    return expr[length-1];
}

int main()
{
    char expr[] = "1C1B1B0A0";
    printf("The value of expression %s is : %c", expr, evaluate(expr)); 
    return 0;
}
