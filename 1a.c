#include <stdio.h>

int linearSearch(int arr[], int n, int key, int index)
{
    if (index == n)
        return -1; // Base case: key not found
    if (arr[index] == key)
        return index;                            // Element found
    return linearSearch(arr, n, key, index + 1); // Recursive call
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
    int arr[] = {5, 8, 12, 7, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    printf("Original Array (Linear Search):\n");
    display(arr, n);

    int result = linearSearch(arr, n, key, 0);

    if (result != -1)
        printf("Element %d found at position %d (0-based index)\n", key, result);
    else
        printf("Element %d not found in the array\n", key);

    return 0;
}
