#include <stdio.h>

// Function prototype
void shellSort(int arr[], int n);
void display(int arr[], int n);

// Function to perform Shell Sort
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Function to display array elements
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {23, 12, 1, 8, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array (Shell Sort):\n");
    display(arr, n);

    shellSort(arr, n);

    printf("Sorted Array :\n");
    display(arr, n);

    printf("\n\n");

    return 0;
}
