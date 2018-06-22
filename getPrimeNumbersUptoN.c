#include <stdio.h>
#include <string.h>

//void printAllPrimeNumbersTillN(int n)
//{
  //int arr[n+1];
  //memset(arr, 0, sizeof(arr));
   
  //for (int i = 2; i <=n; i++)
  //{
    //if (!arr[i])
    //{
      //for (int j = 2*i; j <= n; j+=i)
      //{
	//arr[j] = 1;
      //}
    //}
  //}
  
  //for (int i = 2; i <=n; i++)
  //{
    //if (!arr[i])  printf("%d ", i);
  //}   
//}


//Algorithm : Sieve of Eratosthenes
int getSumOfPrimes(int n)
{
  int arr[n+1];
  memset(arr, 0, sizeof(arr));
   
  for (int i = 2; i <=n; i++)
  {
    if (!arr[i])
    {
      for (int j = 2*i; j <= n; j+=i)
      {
	arr[j] = 1;
      }
    }
  }
  
  int sum = 0;
  for (int i = 2; i <=n; i++)
  {
    if (!arr[i])  sum += i;
  }
  
  return sum;
}

int main()
{
  int n;
  printf("Enter n : ");
  scanf("%d", &n);
  
  //printAllPrimeNumbersTillN(n);
  
  printf("Sum of prime no.s : %d", getSumOfPrimes(n));
  
  return 0;
}
