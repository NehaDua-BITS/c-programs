#include <stdio.h>

int findSmallestMissingPositive(int *arr, int size)
{
  for (int i = 0; i < size;)
  {
    int index;
    if ((arr[i] > 0) && ((index = arr[i] - 1) < size) && i != index)
    {
	int temp = arr[index];
	arr[index] = arr[i];
	arr[i] = temp;
    }
    else
	i++;
  }

  for (int i = 0; i < size; i++)
  {
    printf("\n i = %d %d", i, arr[i]);
  }
  
  for (int i = 0; i < size; i++)
  {
    if (arr[i] != (i+1))
    {
      return i+1;
    }
  } 
  
  return -1;
}

int main()
{
  int arr[] = {5, -20, 2, 1, 0, 10, 3, -14, -50, 4};
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("The smallest missing positive number is : %d", findSmallestMissingPositive(arr, size));
  
  return 0;
}
