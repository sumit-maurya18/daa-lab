#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1; // Base case: not found

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid; // Element found
    else if (arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key); // Search left half
    else
        return binarySearch(arr, mid + 1, high, key); // Search right half
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
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    printf("Original Array (Binary Search):\n");
    display(arr, n);

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element %d found at position %d (0-based index)\n", key, result);
    else
        printf("Element %d not found in the array\n", key);

    return 0;
}
