#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int k)
{
    int i;
    for (i = 0; i < k; i++)
        printf("%d ", arr[i]);
}

int getMinInTempArray(int *temp, int k)
{
    int minIndex = -1;
    
    for (int i = 0; i < k; i++)
    {
        if (minIndex == -1 || (temp[i] < temp[minIndex]))
        {
            minIndex = i;
        }
    }
    
    return minIndex;
}

void findKLargestUsingTempArray(int *arr, int count, int k)
{
    int temp[k];
    
    for (int i = 0; i < k; i++)
        temp[i] = arr[i];
     
    for (int i = k; i < count; i++)
    {
        int minElementIndex = getMinInTempArray(temp, k);        
        if (arr[i] > temp[minElementIndex])
            temp[minElementIndex] = arr[i];            
    }
    
    printArray(temp, k);    
}

//using bubble sort with k rounds
void printKLargestElements(int *arr, int count, int k)
{
    if (k > count)
    {
        printf("Invalid value of k");
        exit(0);
    }
    
    if (k == count)
    {
        printArray(arr, k);
        return;
    }
        
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }      
    
    printf("Largest k elements are : \n");
    printArray(arr+count-k , k);
}

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int count = sizeof(arr) / sizeof(arr[0]);
    printf("The num of elements are : %d\n", count);
    
    int k;
    printf("Enter k : ");
    scanf("%d", &k);
    
    //using bubble sort
    //printKLargestElements(arr, count, k);
    
    //using temp array
    findKLargestUsingTempArray(arr, count, k);
    
    return 0;
}
