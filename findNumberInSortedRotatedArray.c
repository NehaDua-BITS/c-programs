#include <stdio.h>

int findPivotLinear(int *arr, int num)
{
  for (int i=num-1; i>0; i--)
  {
    if (arr[i] < arr[i-1])
      return i-1;
  }
  
  return -1;
}

int findPivotBinary(int *arr, int l, int r)
{
  int mid;  
  mid = (l + r)/2;
  
  if(mid < r && arr[mid] > arr[mid+1])
    return mid;
    
  if(mid > l && (arr[mid] < arr[mid-1]))
      return mid-1;
      
  if (arr[l] <= arr[mid])
    return findPivotBinary(arr, mid + 1, r);
  
  return findPivotBinary(arr, l, mid - 1);
}

int binarySearch(int *arr, int l, int h, int k)
{
  int mid = (l + h)/2;
  
  if (l > h)
    return -1;
    
  if (k == arr[mid])
    return mid;    
  else if (k < arr[mid])
    return binarySearch(arr, l, mid - 1, k);
  else
      return binarySearch(arr, mid + 1, h, k);
      
}

int findUsingPivot(int *arr, int count, int pivot, int k)
{
   if (k == arr[pivot])
    return pivot;
    
   if (k >= arr[0])
      return binarySearch(arr, 0, pivot - 1, k);
   return binarySearch(arr, pivot + 1, count - 1, k);   
}


int findNumUSingSinglePass(int *arr, int l, int h, int k)
{
  int mid = (l + h)/2;
  
  if (l > h)
    return -1;
    
  if (k == arr[mid])
    return mid;
    
  //if first part is sorted  
  if (arr[l] <= arr[mid])
  {
    if (k >= arr[l] && (k <= arr[mid]))
      return findNumUSingSinglePass(arr, l, mid-1, k);
    return findNumUSingSinglePass(arr, mid+1, h, k);
  } 

  //if second part is sorted
  if (k >= arr[mid] && (k <= arr[h]))
    return findNumUSingSinglePass(arr, mid+1, h, k);
    
  return findNumUSingSinglePass(arr, l, mid-1, k);    
}

int main()
{
  int arr[] = {4, 5, 6, 7, 8, 9, 10, 1, 2, 3};
  int num = sizeof(arr)/sizeof(arr[0]);
  
  printf("\nNo. of elements in array : %d", num);
  
  int pivot = findPivotLinear(arr, num);
  printf("\nLinear search pivot = %d", pivot);
  
  pivot = findPivotBinary(arr, 0,  num - 1);
  printf("\nBinary search pivot = %d", pivot);
  
  int k;
  printf("\nEnter number to be found : ");
  scanf("%d", &k);
  printf("\n\nUsing double pass : Number present = %s", findUsingPivot(arr, num, pivot, k) != -1 ? "yes" : "no");
  
  printf("\nUsing single pass : Number present = %s", findNumUSingSinglePass(arr, 0, num - 1, k) != -1 ? "yes" : "no");
  
  return 0;
}
