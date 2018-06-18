#include <stdio.h>
#include <stdlib.h>

void printCommonElements(int *arr1, int *arr2, int *arr3, int n1, int n2, int n3)
{
  int i,j,k;
  for (i = 0, j = 0, k = 0; i < n1 && j < n2 && k < n3; )
  {
    if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
    {
        printf("%d ", arr1[i]);
        i++; j++; k++;
    }
    else if(arr1[i] < arr2[j] || arr1[i] < arr3[k])
    {
      i++;
    }
    else if(arr1[i] > arr2[j] || arr2[j] < arr3[k])
    {
      j++;
    }
    else
      k++;
  }
}

int main()
{
    int arr1[] = {3, 5, 10, 20, 40, 50, 80};
    int arr2[] = {1, 7, 20, 50, 80, 100};
    int arr3[] = {6, 4, 15, 20, 30, 50, 70, 80, 120};
    
    int length1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("No. of elements in array 1 : %d\n", length1);

    int length2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("No. of elements in array 2 : %d\n", length2);

    int length3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("No. of elements in array 3 : %d\n", length3);
    
    printf("\nCommon elements are : \n");
    printCommonElements(arr1, arr2, arr3, length1, length2, length3);
    
    return 0;
}
