#include <stdio.h>

void merge(int array[], int left, int middle, int right)
{
    int i, j, k;
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int leftPart[leftSize], rightPart[rightSize];

    for (i = 0; i < leftSize; i++)
        leftPart[i] = array[left + i];
    for (j = 0; j < rightSize; j++)
        rightPart[j] = array[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftPart[i] <= rightPart[j])
        {
            array[k] = leftPart[i];
            i++;
        }
        else
        {
            array[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        array[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        array[k] = rightPart[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int numbers[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original Array (Merge Sort):\n");
    printArray(numbers, size);

    mergeSort(numbers, 0, size - 1);

    printf("Sorted Array:\n");
    printArray(numbers, size);

    return 0;
}
