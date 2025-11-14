#include <stdio.h>

// Function to heapify a subtree rooted at index 'i'
// 'size' is the total number of elements in the heap
void heapify(int array[], int size, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < size && array[left] > array[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < size && array[right] > array[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        heapify(array, size, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int array[], int size)
{
    // Build a max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    // Extract elements from heap one by one
    for (int i = size - 1; i > 0; i--)
    {
        // Move current root to end
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Call heapify on the reduced heap
        heapify(array, i, 0);
    }
}

// Function to display array elements
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int numbers[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original Array (Heap Sort):\n");
    printArray(numbers, size);

    heapSort(numbers, size);

    printf("Sorted Array:\n");
    printArray(numbers, size);

    return 0;
}
