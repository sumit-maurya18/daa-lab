#include <stdio.h>

#define MAX 20
int setArr[MAX], subsetArr[MAX];
int setSize, targetSum;

// Function to print one subset
void printSubset(int size)
{
    printf("{ ");
    for (int i = 0; i < size; i++)
        printf("%d ", subsetArr[i]);
    printf("}\n");
}

// Recursive function to find subsets with given sum
void findSubsets(int index, int currentSum, int start)
{
    if (currentSum == targetSum)
    {
        printSubset(index);
        return;
    }
    if (currentSum > targetSum || start >= setSize)
        return;

    // Include the current element
    subsetArr[index] = setArr[start];
    findSubsets(index + 1, currentSum + setArr[start], start + 1);

    // Exclude the current element
    findSubsets(index, currentSum, start + 1);
}

int main()
{
    int tempSet[] = {3, 1, 2, 5, 4};
    setSize = sizeof(tempSet) / sizeof(tempSet[0]);
    for (int i = 0; i < setSize; i++)
        setArr[i] = tempSet[i];

    targetSum = 6;

    printf("Sum of Subsets Problem (Backtracking)\n");
    printf("\n\n");

    printf("Given Set: { ");
    for (int i = 0; i < setSize; i++)
        printf("%d ", setArr[i]);
    printf("}\n");
    printf("Target Sum: %d\n", targetSum);
    printf("\nSubsets with sum = %d:\n", targetSum);

    findSubsets(0, 0, 0);

    return 0;
}
