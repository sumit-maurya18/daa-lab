#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place pivot element at correct position
int partition(int array[], int low, int high)
{
    int pivot = array[high]; // Choosing last element as pivot
    int i = low - 1;         // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        { // If current element <= pivot
            i++;
            swap(&array[i], &array[j]); // Swap elements
        }
    }

    swap(&array[i + 1], &array[high]); // Place pivot in correct position
    return i + 1;                      // Return pivot index
}

// Recursive Quick Sort function
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(array, low, high); // Partition the array
        quickSort(array, low, pivotIndex - 1);        // Sort left part
        quickSort(array, pivotIndex + 1, high);       // Sort right part
    }
}

// Function to display array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int numbers[] = {64, 25, 12, 22, 11, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original Array (Quick Sort):\n");
    printArray(numbers, size);

    quickSort(numbers, 0, size - 1);

    printf("Sorted Array:\n");
    printArray(numbers, size);

    return 0;
}
