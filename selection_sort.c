#include <stdio.h>

// function to swap the positions of two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    for(int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for(int i = step + 1; i < size; i++)
        {
            if(array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}

// function to print an array
void printArray(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// driver code
int main(void)
{
    int data[] = {20, 12, 10, 7, 1};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    printf("Sorted array in ascending order: \n");
    printArray(data, size);
}