#include <stdio.h>

// Function to get the maximum value in the array
int getMax(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Function to perform Counting Sort based on a specific digit (exp)
void countingSortByDigit(int array[], int size, int exp)
{
    int output[size];
    int count[10] = {0}; // There are 10 possible digits (0–9)

    // Count occurrences of each digit in the current place
    for (int i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    // Update count[i] so that it contains the position of this digit
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (stable sort)
    for (int i = size - 1; i >= 0; i--)
    {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    // Copy output array back to the original array
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

// Function to perform Radix Sort
void radixSort(int array[], int size)
{
    int max = getMax(array, size);

    // Apply counting sort for every digit (1s, 10s, 100s, etc.)
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortByDigit(array, size, exp);
}

// Function to display the array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int numbers[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original Array (Radix Sort):\n");
    printArray(numbers, size);

    radixSort(numbers, size);

    printf("Sorted Array:\n");
    printArray(numbers, size);

    return 0;
}
