#include <stdio.h>
#include <stdlib.h>

void getNodeDepth(int *arr, int index, int *depth)
{
  if (depth[index])  //if depth is already set
    return;
    
  if (arr[index] == -1) //if it's root node
  {
    depth[index] = 1;
    return;
  }  
  
  if (!depth[arr[index]]) //if depth of parent not set
  {
    getNodeDepth(arr, arr[index], depth);
  }
  
  depth[index] = 1 + depth[arr[index]];
}

int height(int *arr, int n)
{
  int *depth = (int *)calloc(n, sizeof(int));
  
  for (int i = 0; i < n; i++)
  {
    getNodeDepth(arr, i, depth);
  }
  
  int max = -1;
  for (int i = 0; i < n; i++)
  {
    if (depth[i] > max)
      max = depth[i];
  }
  
  return max;
}

int main()
{
  //int arr[] = {1,5,5,2,2,-1,3};
  int arr[] = {-1, 0, 0, 1, 1, 3, 5};
  //int arr[] = {-1};
  
  
  int length = sizeof(arr) / sizeof(arr[0]);
  
  printf("\nThe no. of elements in array = %d", length);
  
  printf("\nHeight of tree = %d", height(arr, length));
  return 0;
}

