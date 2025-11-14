#include <stdio.h>

// Function to perform Counting Sort
void countingSort(int array[], int size)
{
    int output[size];
    int max = array[0];

    // Find the maximum element
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];

    int count[max + 1];

    // Initialize count array with zeros
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Store the frequency of each element
    for (int i = 0; i < size; i++)
        count[array[i]]++;

    // Update count[i] to contain actual position of this element in output
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy sorted elements back to original array
    for (int i = 0; i < size; i++)
        array[i] = output[i];
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
    int numbers[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original Array (Counting Sort):\n");
    printArray(numbers, size);

    countingSort(numbers, size);

    printf("Sorted Array:\n");
    printArray(numbers, size);

    return 0;
}
