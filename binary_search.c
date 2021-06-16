#include<stdio.h>

int binarySearch(int array[], int start_index, int end_index, int element)
{
    while (start_index <= end_index)
    {
        int middle = start_index + (end_index - start_index) /2;
        if (array[middle] == element)
            return middle;
        if (array[middle] < element)
            start_index = middle + 1;
        else 
            end_index = middle - 1;
    }
    return -1;
}

int main(void)
{
    int array[] = {1, 5, 6, 34, 67, 98};
    int n = 6;
    int element = 34;
    int found_index = binarySearch(array, 0, n-1, element);
    if(found_index == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at index %d", found_index);
    }
    return 0;
}