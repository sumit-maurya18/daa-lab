#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;

    // Move boundary of unsorted subarray one by one
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        // Find the minimum element in the unsorted part
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to display array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array (Selection Sort):\n");
    display(arr, n);

    selectionSort(arr, n);

    printf("Sorted Array:\n");
    display(arr, n);

    return 0;
}
